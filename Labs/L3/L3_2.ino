// counter for pressing the button 
const int buttonPin = 2;

bool buttonState = LOW;
int counter = 0;
bool previousState = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if(previousState != buttonState && buttonState == LOW){
    counter++;
  }
  previousState = buttonState;
  Serial.println(counter);
  delay(1);
}
