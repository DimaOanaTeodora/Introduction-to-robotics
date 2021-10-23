const int potPin = A0; 
const int ledPin = 11; // global variables are initialized to 0 by default 

int potValue = 0;
int ledValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT); 
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin); 
  
  //potValue = map(potValue, 0, 1023, 0, 255); 
  //potValue = potValue / 4; -> this works just as well analogWrite(ledPin, ledValue);
  potValue = potValue / 4;
  analogWrite(ledPin, potValue);

}
