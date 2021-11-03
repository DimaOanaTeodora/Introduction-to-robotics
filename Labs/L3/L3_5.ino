// counter for pressing the button 
const int ledPin = 11;
const int buttonPin = 2;

bool buttonState = LOW;

bool previousState = HIGH;
bool ledState = LOW;

int readding = HIGH;
int previousReadding = HIGH;

unsigned int lastDebounceTime = HIGH;
unsigned int debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readding = digitalRead(buttonPin);
  
  if ( readding != previousReadding){
    lastDebounceTime = millis(); 
  }
  if(millis() - lastDebounceTime > debounceDelay){
    if(readding != buttonState){
      buttonState = readding;
      if(buttonState == HIGH){
        ledState = ! ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }
  previousReadding = readding;
}
