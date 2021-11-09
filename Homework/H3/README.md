# Homework #3 :ghost: 
Ghost detector (EMF - electromagnetic field - detector)

Deadline: ```Wednesday, November 10th, 23:59```

# [YouTube demo]()

# Schema

# Requirements

### Components
- a buzzer 
- a 7-segment display (or a led bar / or 8 leds in a row that simulate a led bar)

### Task
- should detect EMF (check body and near outlets. DO NOT INSERT INTO OUTLET - :name_badge: AKA NU-L BAGATI IN PRIZA :name_badge:)
- it should print the value on the 7-segment display (or light the led bar) 
- it should make a sound based on the intensity.

### The catch
:warning: one of the mistakes you can do is not calibrate for the interval on the values you are going to get. 

:warning: Check the link on calibrations.

### Examples
- Search on google for ```Arduino Uno EMF detector```
- [Cool example with bar graph](https://www.youtube.com/watch?v=y1Bke3750WE)
- [Basic example](https://www.youtube.com/watch?v=itgNU3JVj7Q)
- [Averaging Code (aka the catch) var 1](http://www.aaronalai.com/emfdetector-averaging-code)
- [Averaging Code (aka the catch) var 2](http://www.aaronalai.com/emf-detector)
- [Example with 7-segment display](https://www.instructables.com/Arduino-EMF-Detector/)
- [Overachiever (but good to follow and adapt to your own project)](https://create.arduino.cc/projecthub/mircemk/diy-ultra-sensitive-emfdetector-4be895)

### :radioactive: Just to be clear :radioactive: 
- the ```input``` is the EMF using a home-made antenna (can be a wire and a resistor) 
- the ```output``` is some sort of lighting (7-segment values, leds lighting up etc) and a buzzer with intensity (change the 2nd parameter in the tone function based on the intensity)

:sparkle: The purpose of this project is, first of all, ```to have a bit of fun``` and also let you be creative (or lazy) with it. 

:beginner: Bonus points for extra effort.
