// counter for pressing the button 
const int ledPin = 11;
const int buttonPin = 2;

bool buttonState = LOW;
int counter = 0;
bool previousState = HIGH;
bool ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  ledState = ! buttonState;
  digitalWrite(ledPin, ledState);
  
  if(previousState != buttonState && buttonState == LOW){
    counter++;
  }
  previousState = buttonState;
  
  Serial.println(counter);
  delay(1);
}
