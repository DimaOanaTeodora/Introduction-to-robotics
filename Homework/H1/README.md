
# :partying_face:	 Homework #1 
Deadline: ```Wednesday, October 27, 23:59.```

![image](https://user-images.githubusercontent.com/61749814/138553445-86d2af5d-c8ac-44bf-948a-eb28f48fc7e9.png)

### :eyes: [Demo YouTube Video](https://youtu.be/oWc1z4h_uSw)

### :eyes: Schema
![H1_Schema](https://user-images.githubusercontent.com/61749814/138553021-bae9912e-a7ee-4cd0-addc-80ab99e3daa8.png)

## Requirements

### :maple_leaf: Components 
RBG led (1 minimum), potentiometers (3 minimum), resistors and wires (per logic)

### :maple_leaf: Technical Task 
Use a separat potentiometer in controlling each of thecolor of the RGB led (Red,Green and Blue). The control must be done with digital electronics(aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.

### :maple_leaf: Publishing task
You must add the code to the ```Github repo``` and continue updating the README with at least the following details (but feel free to be more creative):
  1.  Task Requirements
  2.  Picture of the setup
  3.  Link to video showcasing functionality (I recommend youtube,  butanything I can access is fine)
  4.  Remember to publish the video in the correct orientation. :thumbsdown: Don’t do this:  https://youtu.be/Y8H0PlUtcto5. Hand in the homework on MS teams when done - aka when github is up to date

### :maple_leaf: Coding task
- Coding style is of utmost importance. 
- You must have a perfectly clean code in order to receive the maximum grade. 
- Keep in mindthat magic numbers are not accepted, although you might see them in the lab (as a trade-off for speed). Remember to be consistent in your style, check  the  style  guide  and  the  provided  style  document  and  use  correct spacing. 
- Example used in lab which would not yield the maximum grade:  

``` analogWrite(ledPin, potValue / 4)``` or ```voltage = potValue * 5.0 / 1023.0.```

- :thumbsdown: Mistakes observed there
    1.  ```potValue / 4```is not precise, since the value does not always split into 4 perfectly.  Use the ```map()``` function.
    2.  ```4``` is a magic number, it should be a constant.
    3.  We calculate the value inside the ```analogWrite``` function.
    4.  Correct  version: 
    ```
    brightness  =  map(potValue,  0,  1023,  0,  255);
    analogWrite(ledPin, brightness)
    ```
    5.  ```5.0```  and  ```1023.0```  are  magic  numbers.   They  should  be  replaced  withconstants, such as ```maxAnalogValue```, ```maxVoltageValue``` etc.
