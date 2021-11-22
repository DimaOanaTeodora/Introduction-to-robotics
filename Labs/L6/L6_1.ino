#include<LiquidCrystal.h>

const int RS = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const int trigPin = 9;
const int echoPin = 10;

long duration = 0;
int distance = 0;
int reading = 0;

LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);

void setup() {
 lcd.begin(16,2); // initializez obiectul pt un display de 16 pe 2
 lcd.print("Hello world!");
 lcd.setCursor(0,1);

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 Serial.begin(9600);
}

void loop() {
  lcd.clear();
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  reading = duration * 0.034 / 2;
  if(reading < 50){
    distance = reading;
  }

  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(100);
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  //lcd.setCursor(4,1);
  //lcd.blink();
  //lcd.scrollDisplayRight();
  //delay(500);
  //lcd.print("bye");//printul muta cursorul in ultima pozitie

}
