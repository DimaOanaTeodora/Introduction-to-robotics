```const int redPinCar = 4;
const int greenPinCar = 2;
const int yellowPinCar = 3;

const int greenPin = 12;
const int redPin = 13;

bool stateRedPinCar = LOW;
bool stateYellowPinCar = LOW;
bool stateGreenPinCar = HIGH;

bool stateRedPin = HIGH;
bool stateGreenPin = LOW;

int firstTime = 1;

const int pushButton = 7;

bool buttonState = 1;

void setup (){
  
pinMode(greenPinCar, OUTPUT);
pinMode(yellowPinCar, OUTPUT);
pinMode(redPinCar, OUTPUT);
  
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
  
pinMode(pushButton, INPUT_PULLUP);
  
Serial.begin(9600);
  
}
void state1(){
  /*green light for cars,
red light for people, no sounds.
Duration: indefinite*/
  
  	stateRedPinCar = LOW;
	stateYellowPinCar = LOW;
	stateGreenPinCar = HIGH;

	stateRedPin = HIGH;
	stateGreenPin = LOW;
  
  	updateStates();
}

void state2(){
  /*the light should be yellow for cars
red for people and no sounds.
Duration: 3 seconds.*/
  	stateRedPinCar = LOW;
	stateYellowPinCar = HIGH;
	stateGreenPinCar = LOW;

	stateRedPin = HIGH;
	stateGreenPin = LOW;
  
  	updateStates();
  
    delay(3000);
}

void state3(){
  /*red for cars
green for people
a beeping sound from the buzzer at a constant interval.
Duration: 10 seconds.*/
  	stateRedPinCar = HIGH;
	stateYellowPinCar = LOW;
	stateGreenPinCar = LOW;

	stateRedPin = LOW;
	stateGreenPin = HIGH;
  
  	updateStates();
  
  	//beeping constant interval low
  	delay(10000);
}
void state4(){
  /*red for cars
blinking green for people
a beeping sound from the buzzer,
at a constant interval, 
faster than the beeping in state 3.*/
  	stateRedPinCar = HIGH;
	stateYellowPinCar = LOW;
	stateGreenPinCar = LOW;

	stateRedPin = LOW;
	stateGreenPin = HIGH;
  
  	updateStates();
  
  	//beeping constant interval faster
  	delay(10000);
}

void updateStates(){
digitalWrite(greenPin, stateGreenPin);
digitalWrite(redPin, stateRedPin);
 
digitalWrite(greenPinCar, stateGreenPinCar);
digitalWrite(redPinCar, stateRedPinCar);
digitalWrite(yellowPinCar, stateYellowPinCar);
}

int verifyState1(){
  if (stateRedPinCar == LOW &&
      stateYellowPinCar == LOW &&
	stateGreenPinCar == HIGH &&

	stateRedPin == HIGH &&
      stateGreenPin == LOW ){
    return 1;
  }
  return 0;
}
void loop (){
  
state1();

buttonState = digitalRead(pushButton);
  
Serial.println(buttonState);


if (buttonState == 0 && verifyState1() == 1)
{
  buttonState = 1;
  delay(10000);//counting ten second after button press
  state2();
  state3();
  state4();
}

}
```
![image](https://user-images.githubusercontent.com/61749814/139828343-73d4467e-4bca-476d-9dce-9c93aeaa955e.png)
