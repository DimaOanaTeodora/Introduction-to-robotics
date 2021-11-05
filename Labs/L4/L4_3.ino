// cycle through all the digits
//joystick => TODO: debounce
const int pinSW = 10;
const int pinX = A0;
const int pinY = A1;

bool switchState = LOW;
int xValue = 0;
int yValue = 0;
bool lastState = LOW;

bool joyMoved = false;

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;

const int segSize = 8;
bool dpState = LOW;
bool state = HIGH;

int segments[segSize]={pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP};

int index = 0;

int minTreshold = 350;
int maxTreshold = 700; //variables

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
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);

  Serial.begin(9600);
}

void loop() {

  xValue = analogRead(pinX);
  //yValue = analogRead (pinY);
  switchState = digitalRead(pinSW);

  if(xValue > maxTreshold && joyMoved == false){
    index ++;
    joyMoved = true;
  }
  if(xValue < minTreshold && joyMoved == false){
    index --;
    joyMoved = true;
  }
  if(index >9){
    index = 0;
  }
  if(index <0){
    index = 9;
  }

  if(xValue > minTreshold && xValue < maxTreshold){
    joyMoved = false;
  }
  
   if(switchState == LOW && switchState != lastState){
    dpState = !dpState;
  }
  
  lastState = switchState;
  displayNumber(index, dpState);
  
  /*Serial.print("Switch: ");
  Serial.print(switchState);
  Serial.print("    |     ");
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print("    |     ");
  Serial.print("Y-axis: ");
  Serial.print(yValue);
  Serial.println("");
  
  delay(100);
  */
  
  /*displayNumber(index, dpState);

  index ++;
  if(index >9){
    index = 0;
    dpState = !dpState;
  }
  
  delay(500);*/

}
