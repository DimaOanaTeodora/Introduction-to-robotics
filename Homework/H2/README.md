# Homework #2 :alien:
:red_circle: :yellow_circle: :green_circle: Crosswalk simulator: traffic lights for people and cars :red_circle: :yellow_circle: :green_circle:

Deadline: ```Wednesday, November 3rd, 23:59.```
 
### [Youtube Demo]()

### Schema
![image](https://user-images.githubusercontent.com/61749814/139914040-c4f3a10c-122a-4f36-980e-42997d065d17.png)


## Requirements
### Components 
- 5 LEDs: 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green)
- 1 button
- 1 buzzer
- resistors and wires (per logic)

### General description
Building the traffic lights for a crosswalk. See the states it needs to go through. Also, see the uploaded video (the intervals are different, but the states flow is the same). It’s a traffic lights system for people and cars - don’t overthink it.

### The system has the following states
- State 1: (default, reinstated after state 4 ends)
  - green light for cars,
  - red light for people, no sounds. 
  - Duration: indefinite, changed by pressing the button.
- State 2 (initiated by counting down 10 seconds after a button press)
  - the light should be yellow for cars
  - red for people and no sounds.
  - Duration: 3 seconds.
- State 3 (iniated after state 2 ends)
  - red for cars
  - green for people
  - a beeping sound from the buzzer at a constant interval. 
  - Duration: 10 seconds.
- State 4 (initiated after state 3 ends)
  - red for cars
  - blinking green for people 
  - a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3.
  
:warning: Pressing the button in any state other than ```state 1``` shouldn't yield any actions.

### Publishing task
1. Task Requirements
2. Picture of the setup
3. Link to video showcasing functionality 
4. Remember to publish the video in the correct orientation
5. Hand in the homework on MS teams when done - aka when Github is up to date

### Coding task
:biohazard: Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. An important coding challenge present in this task is using ```millis()``` instead of ```delay()```.

:warning: However, remember that the bulk of the grade is if the projects works.

:no_entry: Do not tend to small details unless you have the entire functionality done.
