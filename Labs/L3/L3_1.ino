const int buttonPin = 2;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool pinState = digitalRead(buttonPin);
  if(pinState == LOW){
    counter++;
  }
  Serial.println(counter);
}
