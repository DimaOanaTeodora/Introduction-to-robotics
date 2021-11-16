# Homework #4 :zero:. :zero:. :zero:. :zero:.
Deadline: ```Wednesday, November 17th, 23:59.```

# [YouTube demo]()
# States
```
 * STATE 1: blinking DP; moving on the OY axis the DP => changeDecimalPointPosition() method
 * STATE 2: fixed DP; moving on the OX axis change the value of the digit; =>  changeDigitValue() method
```

# Requirements 
The current homework involves using a ```joystick``` in setting the values on each digit of ```a 4-digit 7-segment display``` connected to a 
```shift register 74hc595```. 

:warning: For maximum grade, you muse use ```interrupts```. :warning:

:stars: For *bonus* you can save the last value in ```eeprom```. :stars:

### Components
 - a joystick
 - a 4 digit 7-segment display
 - a 74hc595 shift register
 
### Task

You can use ```a joystick axis``` to cycle through the 4 digits; using the other axis does nothing. 
A blinking decimal point shows the current digit position. When pressing the button (:warning: use ```interrupt``` for maximum points :warning:), you lock in on the 
selected digit and enter the second state. In this state, the decimal point stays always on, no longer
blinking and you can no longer use the axis to cycle through the 4 digits.
Instead, using the other axis, you can increment on decrement the number
on the current digit. Pressing the button again returns you to the previous
state. 

:star2: For bonus, save the last value in ```eeprom``` and load it when starting arduino. 

Also, keep in mind that when changing the number, you must
increment it for each joystick movement - it should not work continuosly
increment if you keep the joystick in one position.

## Useful links
### Interrupts
1. [link 1](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
2. [link 2](https://create.arduino.cc/projecthub/rafitc/interrupts-basics-f475d5)
3. [link 3](https://www.youtube.com/watch?v=QtyOiTw0oQc)
4. [link 4](https://www.google.com/search?q=arduino+uno+interrupts&oq=arduino+uno+interrupts&aqs=chrome..69i57j0i67j0i512l7.5123j0j7&sourceid=chrome&ie=UTF-8)

### EEPROM:
1. [link 1](https://www.arduino.cc/en/Reference/EEPROM)
2. [link 2](https://www.youtube.com/watch?v=ShqvATqXA7g)
3. [link 3](https://www.google.com/search?q=arduino+uno+eeprom&oq=arduino+uno+eeprom&aqs=chrome.0.0i512l5j0i22i30l5.3266j0j7&sourceid=chrome&ie=UTF-8)
