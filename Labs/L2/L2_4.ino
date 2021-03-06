const int ledPin = 9; 
int brightness = 0; // how bright the LED is 
int fadeAmount = 5; // how many units to fade the LED by

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // set the brightness of pin 9: 
  analogWrite(ledPin, brightness);
   
  // change the brightness for next time through the loop: 
  brightness = brightness + fadeAmount; 
  
  // reverse the direction of the fading at the ends of the fade: 
  if (brightness <= 0 || brightness >= 255) { 
    fadeAmount = -fadeAmount; 
  } 
  // wait for 30 milliseconds to see the dimming effect 
  delay(30);
}
