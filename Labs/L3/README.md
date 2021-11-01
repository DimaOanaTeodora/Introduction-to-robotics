## Blinking leds for traffic lights
```
const int redPin = 4;
const int greenPin = 2;
const int yellowPin = 3;

void setup (){
  
pinMode(greenPin, OUTPUT);
pinMode(yellowPin, OUTPUT);
pinMode(redPin, OUTPUT);
  
}
void loop (){

digitalWrite(redPin, HIGH);
delay(1000);
digitalWrite(redPin, LOW);
delay(1000);

digitalWrite(yellowPin, HIGH);
delay(1000);
digitalWrite(yellowPin, LOW);
delay(1000);

digitalWrite(greenPin, HIGH);
delay(1000);
digitalWrite(greenPin, LOW);
delay(1000);

}
```
![image](https://user-images.githubusercontent.com/61749814/139747320-31d30e83-61eb-4833-b363-0d55bed18ad6.png)

## Cars and people
```
const int redPinCar = 4;
const int greenPinCar = 2;
const int yellowPinCar = 3;

const int greenPin = 12;
const int redPin = 13;

bool stateRedPinCar = HIGH;
bool stateYellowPinCar = LOW;
bool stateGreenPinCar = LOW;

bool stateRedPin = LOW;
bool stateGreenPin = HIGH;

int direction = 1;
int firstTime = 1;

void setup (){
  
pinMode(greenPinCar, OUTPUT);
pinMode(yellowPinCar, OUTPUT);
pinMode(redPinCar, OUTPUT);
  
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
  
}
void updateState(){
digitalWrite(greenPin, stateGreenPin);
digitalWrite(redPin, stateRedPin);
 
digitalWrite(greenPinCar, stateGreenPinCar);
digitalWrite(redPinCar, stateRedPinCar);
digitalWrite(yellowPinCar, stateYellowPinCar);
}

void updatePeople(){
  	stateGreenPin = ! stateGreenPin;
	stateRedPin = ! stateRedPin;
  
  	digitalWrite(greenPin, stateGreenPin);
	digitalWrite(redPin, stateRedPin);
 
}
void updateCars(){
  if (direction == 1){
    // 1 -> red to green for cars
    stateRedPinCar = ! stateRedPinCar;
    digitalWrite(redPinCar, stateRedPinCar);
    
    delay(1000);
	digitalWrite(yellowPinCar, ! stateYellowPinCar);
    delay(1000);
    digitalWrite(yellowPinCar, stateYellowPinCar);
    
    delay(1000);
    stateGreenPinCar = ! stateGreenPinCar;
	digitalWrite(greenPinCar, stateGreenPinCar);
    
  }
  else{
    // -1 -> green to red for cars
    stateGreenPinCar = ! stateGreenPinCar;
	digitalWrite(greenPinCar, stateGreenPinCar);
    
    delay(1000);
	digitalWrite(yellowPinCar, ! stateYellowPinCar);
    delay(1000);
    digitalWrite(yellowPinCar, stateYellowPinCar);
    
    delay(1000);
    stateRedPinCar = ! stateRedPinCar;
    digitalWrite(redPinCar, stateRedPinCar);
    
  }
  direction *= -1;
  
}

void loop (){
  
  if (firstTime == 1){
    
	updateState();
    firstTime = 0;
  }
delay(4000); 
  
updatePeople();
  
delay(2000);

updateCars();
 
}
```
![image](https://user-images.githubusercontent.com/61749814/139752860-2bc12637-d3c6-4426-af1c-5b3e6ce49fca.png)
