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
unsigned long previousMillis2 = 0; 
unsigned long currentMillis2 = 0;
unsigned long previousMillis3 = 0; 
unsigned long currentMillis3 = 0;
unsigned long previousMillis4 = 0; 
unsigned long currentMillis4 = 0;
unsigned long prevMillis3 = 0; 
unsigned long curMillis3 = 0;
unsigned long prevMillis4 = 0; 
unsigned long curMillis4 = 0;

const long interval = 1000; //1 second

int start1 = 0;
int start2 = 0;
int start3 = 0;
int start4 = 0;
int start = 0;

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
   
}
int choiceBuzzer = 1;
void beepingState3(){

     if(choiceBuzzer == 1){
       tone(buzzerPin, buzzerTone, 700);
     }
     else
     {
      noTone(buzzerPin);
     }
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
   
}
int choiceBuzzerAndLight = 1;
void blinkingAndBeepingState4(){
    //blinking green light for people
    //beeping constant interval faster
    
      if(choiceBuzzerAndLight == 1){
        tone(buzzerPin, buzzerTone, 700);
        digitalWrite(greenPin, LOW);
      }
      else{
        noTone(buzzerPin);
        digitalWrite(greenPin, HIGH);
      }
      
}

int verifyState1(){
  
  if (stateRedPinCar == LOW && stateYellowPinCar == LOW && stateGreenPinCar == HIGH && stateRedPin == HIGH && stateGreenPin == LOW ){
    return 1;
  }
  return 0;
}

int currentButtonState = 1;

void pushButton(){
  buttonState = digitalRead(pushButtonPin);
  
  if(currentButtonState == 1 && buttonState == 0){
    previousMillis = millis();
    currentButtonState = 0;
    start1 = 0;
    start2 = 0;
    start3 = 0;
    start4 = 0;
  }
}

void loop (){
  
  
  pushButton();
  Serial.println(currentButtonState);
  
  if(currentButtonState == 0){
          currentMillis = millis(); 
          
          if (verifyState1() == 1 && start1 == 0 && currentMillis - previousMillis >= 10 * interval){
            start1 = 1;
        
            state2();
            previousMillis2 = millis();
            
          }else if (start1 == 1 && start2 == 0){
            currentMillis2 = millis();
             
            if (currentMillis2 - previousMillis2 >= 3 * interval){
              
              start2 = 1;
              state3();
              
              previousMillis3 = millis();
              prevMillis3 = millis();
            }
           
          }
          else if (start1 == 1 && start2 == 1 && start3 == 0){
           
            currentMillis3 = millis();
             
            if (currentMillis3 - previousMillis3 < 10 * interval){
              
                //beeping constant interval low
                curMillis3 = millis();
                
                if (curMillis3 - prevMillis3 >= interval / 2){
                  choiceBuzzer *= -1;
                  prevMillis3 = curMillis3;
                }
                
                beepingState3();
            }
            
             if (currentMillis3 - previousMillis3 >= 10 * interval){
             
              start3 = 1;
              
              previousMillis4 = millis();
              prevMillis4 = millis();
            }
          }
          else if (start1 == 1 && start2 == 1 && start3 == 1 && start4 == 0){
              currentMillis4 = millis();
               
              if (currentMillis4 - previousMillis4 < 4 * interval){
                /*
                 * red for cars
                 * blinking green for people
                 * a beeping sound from the buzzer at a constant interval, faster than the beeping in state 3.
                 */
                
                  curMillis4 = millis();
                  
                  if (curMillis4 - prevMillis4 >= interval / 4){
                    choiceBuzzerAndLight *= -1;
                    prevMillis4 = curMillis4;
                  }
                  
                   blinkingAndBeepingState4();
              }
              
               if (currentMillis4 - previousMillis4 >= 5 * interval){
                  start4 = 1;
                  state1();
                  currentButtonState = 1;
              }

         }          
  }
  
}
