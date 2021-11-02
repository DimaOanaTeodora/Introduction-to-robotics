const int redPinCar = 4;
const int greenPinCar = 2;
const int yellowPinCar = 3;

bool stateRedPinCar = LOW; 
bool stateYellowPinCar = LOW;
bool stateGreenPinCar = HIGH; 
bool stateRedPin = HIGH;
bool stateGreenPin = LOW;

const int greenPin = 12;
const int redPin = 13;

const int pushButtonPin = 7;

bool buttonState = 1;

const int buzzerPin = 8;
int buzzerTone = 500;

unsigned long previousMillis = 0; 
unsigned long currentMillis = 0;

const long interval = 10000; //10 seconds

void setup (){
  
  pinMode(greenPinCar, OUTPUT);
  pinMode(yellowPinCar, OUTPUT);
  pinMode(redPinCar, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
    
  pinMode(pushButtonPin, INPUT_PULLUP);
  
  state1();
  
  Serial.begin(9600);
  
}
void state1(){
  /*
   * green light for cars,
   * red light for people, no sounds
   * duration: indefinite
   */
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
 
  digitalWrite(greenPinCar, HIGH);
  digitalWrite(redPinCar, LOW);
  digitalWrite(yellowPinCar, LOW);
  
}

void state2(){
  /*
   * yellow for cars
   * red for people and no sounds 
   * duration: 3 seconds.
   */
   
   stateGreenPinCar = LOW;
   digitalWrite(greenPinCar, stateGreenPinCar);
  
   stateYellowPinCar = HIGH;
   digitalWrite(yellowPinCar, stateYellowPinCar);
   
   delay(3000);
}
void beepingState3(){
      
     tone(buzzerPin, buzzerTone, 300);
      
     delay(300);
      
     noTone(buzzerPin);
      
     delay(1000);
}
void state3(){
  /*
   * red for cars
   * green for people
   * a beeping sound from the buzzer at a constant interval
   * duration: 10 seconds
   */
   stateGreenPin = HIGH;
   stateRedPin = LOW;
   digitalWrite(greenPin, stateGreenPin);
   digitalWrite(redPin, stateRedPin);
 
   stateRedPinCar = HIGH;
   stateYellowPinCar = LOW;
   digitalWrite(redPinCar, stateRedPinCar);
   digitalWrite(yellowPinCar, stateYellowPinCar);
   
    //beeping constant interval low
    //delay(10000);
  
    for( int i = 0; i < 10; i++ ){
     beepingState3();
   }
}
void blinkingAndBeepingState4(){
    //blinking green light for people
    //beeping constant interval faster
    
      tone(buzzerPin, buzzerTone, 300);
      digitalWrite(greenPin, LOW);
      
      delay(500);
      
      noTone(buzzerPin);
      digitalWrite(greenPin, HIGH);
      
      delay(500);
}
void state4(){
  /*
   * red for cars
   * blinking green for people
   * a beeping sound from the buzzer at a constant interval, faster than the beeping in state 3.
   */
   
    for( int i = 0; i < 3; i++ ){
      
      blinkingAndBeepingState4();
         
   }
  
    //beeping constant interval faster
    //delay(10000);
}


int verifyState1(){
  
  if (stateRedPinCar == LOW && stateYellowPinCar == LOW && stateGreenPinCar == HIGH && stateRedPin == HIGH && stateGreenPin == LOW ){
    return 1;
  }
  return 0;
}

void loop (){
  
  Serial.println(buttonState);

  if (buttonState == 0 && verifyState1() == 1){
    
          currentMillis = millis(); 
  
          if (currentMillis - previousMillis >= interval){
            
            buttonState = 1;
            
            state2();
            //delay(3000);
            state3();
            state4();
            
            state1();
          }
  }
  else{
      buttonState = digitalRead(pushButtonPin);
      
      if (buttonState == 0){  
        previousMillis = millis();
      }
  }
  
}
