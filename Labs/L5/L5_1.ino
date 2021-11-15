// Define Connections to 74HC595 
// Test conection

const int dataPin = 12; // DS
const int latchPin =  11; // STCP
const int clockPin = 10; // SHCP

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int displayCount = 4;

const int displayDigits[] = {
  segD1, segD2, segD3, segD4
};

bool registers[8];

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW); 
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 7; i >= 0; i--) {
    registers[i] = HIGH;
    writeReg();
    delay(100);
  }

  for (int i = 0; i < 8; i++) {
    registers[i] = LOW;
    writeReg();
    delay(100);
  }
  
}

void writeReg() {
  digitalWrite(latchPin, LOW);
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, registers[i]);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
}
