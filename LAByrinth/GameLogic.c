#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "display.h"
#include "MapGenerator.h"

//checks whether the player has landed on the right spot to win the current game
bool checkWin (char position[2]){
    for (int i = 0; i < 2; i ++){
    	if (map[poistion[i]] == WIN_POS){
    		return true;
    	}
    }

    return false;
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