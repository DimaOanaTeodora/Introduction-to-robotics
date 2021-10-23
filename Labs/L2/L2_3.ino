const int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledPin, 10); //10, 20,..100..200 -> the intensity of the led raise
}
