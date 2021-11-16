#include <EEPROM.h>
//shift register
const int dataPin = 12; // DS
const int latchPin =  11; // STCP
const int clockPin = 10; // SHCP

// 4 digits 7 segment display
const int segDisplay1 = 7;
const int segDisplay2 = 6;
const int segDisplay3 = 5;
const int segDisplay4 = 4;

const int segmentCount = 4;
const int displayDigits[] = {
  segDisplay1, segDisplay2, segDisplay3, segDisplay4
};

byte indexSegmentDisplay = 0;
byte segmentDisplayValues[segmentCount] = {0, 0, 0, 0}; //for eeprom storage

//state
/*
 * STATE 1: blinking DP; moving on the OY axis the DP => changeDecimalPointPosition
 * STATE 2: fixed DP; moving on the OX axis change the value of the digit; =>  changeDigitValue
*/
int state = 1; // values: 1 or 2   

//decimal point (DP)
int decimalPointState = HIGH;
const int decimalPointBlinkDelay = 200;

// joystick switch
const int joySwitchPin = 2;
const int joyYPin = A1;
const int joyXPin = A0; 

const int minTreshold = 200;
const int maxTreshold = 800;

bool joyMoved = false;

byte digitArray[10] = {
  B11111100, // bit state for 0 -//-
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
};

// Timing onstants
unsigned long startTimeForBlink = 0;
unsigned long lastStateChange = 0;
const int multiplexingDelay = 5; 
const int stateChangeDelay = 700; 

void setup () {
  pinMode(joySwitchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(joySwitchPin), switchStates, FALLING); // switch state when you push the button
  
  pinMode(joyYPin, INPUT);
  pinMode(joyXPin, INPUT);
  
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  for (int i = 0; i < segmentCount; ++ i) {
    pinMode(displayDigits[i], OUTPUT);
  }

  //First show of the display
  changeDecimalPointPositionInitilization();  
  readFromMemory();
}

void saveToMemory(int indexSegmentDisplay) {
  EEPROM.write(indexSegmentDisplay, segmentDisplayValues[indexSegmentDisplay]);
  EEPROM.write(segmentCount, indexSegmentDisplay); //save display index 
}

void readFromMemory() {
  for (int i = 0; i < segmentCount; ++ i) {
    segmentDisplayValues[i] = EEPROM.read(i);
  }
  indexSegmentDisplay = EEPROM.read(segmentCount); // get current display index;
}

void writeRegister(int digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit); //Most significant bit first
  digitalWrite(latchPin, HIGH);
}

void showSegmentDisplay(int segmentIndex) {
  for (int i = 0; i < segmentCount; ++ i) {
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[segmentIndex], LOW);
}

void showSegmentDisplayValues() {
  for (int i = 0; i < segmentCount; ++ i) {
    int digitToDisplay = digitArray[segmentDisplayValues[i]];
    
    if (i == indexSegmentDisplay && decimalPointState == HIGH) {
      digitToDisplay ^= 1;// last bit is the DP => xoring the value with 1 to light it
    }
    
    writeRegister(digitToDisplay);
    showSegmentDisplay(i);
    delay(multiplexingDelay); //delay for multiplexing
  }
}
              
void changeDecimalPointPositionInitilization() {
  if (state == 2) {//if the previous state was 2
    saveToMemory(indexSegmentDisplay);// save the new value in eeprom
  }
  state = 1;
  joyMoved = false;
  decimalPointState = HIGH;

  startTimeForBlink = millis();
}

void blinkDecimalPoint(){
  unsigned long current = millis();
  
  if (current - startTimeForBlink > decimalPointBlinkDelay) {
    decimalPointState = !decimalPointState;
    startTimeForBlink = current;
  }
}
void changeDecimalPointPosition() {
  int joyY = analogRead(joyYPin);
  
  if(joyY > maxTreshold && joyMoved == false) {
    indexSegmentDisplay -= 1; //left -> right
    joyMoved = true;
  }else if(joyY < minTreshold && joyMoved == false) {
    indexSegmentDisplay += 1; //right -> left
    joyMoved = true;
  }

  if (joyMoved == true && joyY >= minTreshold && joyY <= maxTreshold) {
    joyMoved = false;
  }

  // overflow for last right or last left position
  if(indexSegmentDisplay == segmentCount) {
    indexSegmentDisplay = 0;
  } else if(indexSegmentDisplay == 255) {
    indexSegmentDisplay = segmentCount - 1;
  }

  blinkDecimalPoint();
}

void changeDigitValueInitilization() {
  state = 2;
  decimalPointState = HIGH;
}

void changeDigitValue() {
  int joyX = analogRead(joyXPin);
  
  if(joyX > maxTreshold && joyMoved == false) {
    segmentDisplayValues[indexSegmentDisplay] += 1; // 0, 1, 2, 3....
    joyMoved = true;
  }else if(joyX < minTreshold && joyMoved == false) {
    segmentDisplayValues[indexSegmentDisplay] -= 1; //9, 8, 7, ...
    joyMoved = true;
  }

  if(joyMoved == true && joyX >= minTreshold && joyX <= maxTreshold) {
    joyMoved = false;
  }

  // overflow for 10 and -1 => 0 and 9
  if(segmentDisplayValues[indexSegmentDisplay] == 10) {
    segmentDisplayValues[indexSegmentDisplay] = 0;
  } else if(segmentDisplayValues[indexSegmentDisplay] == 255) {
    segmentDisplayValues[indexSegmentDisplay] = 9;
  }
}

void switchStates() {
  unsigned long current = millis();
  
  if(current - lastStateChange < stateChangeDelay) {
    return;
  }
  lastStateChange = current;

  if(state == 1){
    changeDigitValueInitilization();
  }
  else{
    changeDecimalPointPositionInitilization();
  }
}

void loop() {
  if(state == 1){
    changeDecimalPointPosition();
  }
  else{
    changeDigitValue();
  }
  
  showSegmentDisplayValues(); //multiplexing
}
