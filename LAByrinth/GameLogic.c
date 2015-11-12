#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "display.h"
#include "MapGenerator.h"

//checks whether the player has landed on the right spot to win the current game
bool checkWin (char[2]){
    if (
}

//reads and changes the player's position from the input from the accelerometer
void update() {
    
}

void tick() {

}

bool redraw(){
    char* newMap =
}

void logic(){
    bool flag = false;
    
    while(!flag){
        update();
        tick();
        flag = redraw();
    }
}