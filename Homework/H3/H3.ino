// Ghost Detector 

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;

const int buzzerPin = 12;
const int buzzerTone = 50;
const int buzzerDuration = 700;

const int antenaPin = A5;
int antenaVal = 0; 
int senseLimit = 200; 

int updateTime = 100; //the interval for delay()

const int segSize = 8;

int segments[segSize]={pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP};

int index = 0;

const int readingCounter = 15;
int readings[readingCounter];  
int total = 0;                                                     
int number = -1;

const int noOfDigits = 10;
//matrix
bool digitMatrix [noOfDigits][segSize-1]={
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber (byte digit, bool decimalPoint){
  for (int i = 0; i < segSize - 1; i++){
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, decimalPoint);
}

void setup() {
  for (int i = 0; i< segSize ; i++){
    pinMode(segments[i], OUTPUT);
  }

  // initialize all the readings to 0
  for (int i = 0; i < readingCounter; i++)
    readings[i] = 0;                      
    
  Serial.begin(9600);
}

int averageCalculator(){
    antenaVal = constrain(antenaVal, 1, senseLimit);  
    antenaVal = map(antenaVal, 1, senseLimit, 1, 1023);  // remap the constrained val within a 1 to 1023 range

    total -= readings[index];               
    readings[index] = antenaVal; 
    total += readings[index];               
    index += 1;                    

    if(index >= readingCounter){               
      index = 0;
    }
      
    return total / readingCounter;
}

void loop() {
  antenaVal = analogRead(antenaPin);  
  
  if(antenaVal >= 1){
    
    int average = averageCalculator();
    
    if (average > 50){                
      number = 0;
    }
    if (average > 150){              
       number = 1;
    }
    if (average > 250){
       number = 2;
    }
    if (average > 350){
       number = 3;
    }
    if (average > 450){ 
       number = 4;
    }
    if (average > 550){
       number = 5;
    }
    if (average > 650){
       number = 6;
    }
    if (average > 750){
       number = 7;
    }
    if (average > 850){
       number = 8;
    }
    if (average > 950){
       number = 9;
    }

    Serial.println(average);
    
    displayNumber(number, HIGH);
    tone(buzzerPin, (number+2)* buzzerTone, buzzerDuration);   
     
    delay(updateTime);
    
    noTone(buzzerPin);
    displayNumber(number, LOW);
  }
}
