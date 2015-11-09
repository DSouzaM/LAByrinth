# LAByrinth

## Group Members
* Matt D'Souza
* Valeria Hernandez
* Jing Li
* Denton Liu
* Holly Oegema

Description: 
This project is a labyrinth/maze game in which a “ball” is rolled around a maze with pitfalls and walls. The primary characteristic of the Booster Pack™ that will be utilized by this program is the accelerometer. It is used to control the position of the ball. Other features of the board which can be taken advantage of include: the potentiometer to change the speed of the ball, the buttons to change maps or difficulties, the LED to display to update the users on the state of the game. Finally, our game will have multiple (possibly randomly generated) maps and variable difficulties to satisfy a multitude of users.

#Library Functions 

##Development
void log(char[] str, int n); // logs a character array of size n to PC interface


##Input
char[2] updateTilt(); // returns x and y tilt values


##Output

// graphics


#Game Logic
/* General format
while(true) {
  update();
  tick();
  redraw();
  
  
}

void update() {
// read inputs
// change variables
}
void tick() {
// game logic for every time interval
  void checkWin (char[2]); //Check the ball's current position and whether the user has beaten the game
}
void redraw() {
// graphics and other output
}
*/

##Movement
```
char determineDirection (char[2], char[2]); // reads in the coordinates and determine which direction the ball will be moving in
char determineAccel (char[2], char); // reads in the coordinates and direction and determine how much the ball should be accelerated

```

##Display
```
void updateBallPosition (char[2]); // displays and updates the ball's new position based on updateTilt();
void updateWin (bool); //displays the winning message

```


##Map Generator



