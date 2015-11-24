#include <stdio.h>
#include "display.h"
#include "MapGenerator.h"
#include "ball.h"
#include "GameLogic.h"

long start;
char theMap[32][128] = {{0}};
float dx, dy;
Ball theBall;
int fps;
//checks whether the player has landed on the right spot to win the current game

/*char checkWin (char row, char col, const char map[32][128]){
    int checkRow, checkCol;
    for (checkRow = row; checkRow < row + BALL_WIDTH; checkRow++){
    	for (checkCol = col; checkCol < col + BALL_WIDTH; checkCol++) {
    		if (map[checkRow][checkCol] == WIN_POS){
				return 1;
    		}
    	}
    }

    return 0;
}*/

void setupGame() {
    fps = 1 + get_potentiometer()/30;
    theBall.prev_x = 0;
    theBall.prev_y = 0;
    theBall.x = 4;
    theBall.y = 4;
    generateMap(0,theMap);

    put_bitmap_display(theMap);
    start = millis();
}

//reads and changes the player's position from the input from the accelerometer
void updateGame() {
    long now = millis();
    fps = 1 + get_potentiometer()/30;

    if (now - start >(1000/fps)) {
        start = now;    
        dx = 0.5 - get_switch(0); // read from accelerometer
        dy = 0.5 - get_switch(1); // read from accelerometer
        char futureX = getFutureX(theBall,dx);
        char futureY = getFutureY(theBall,dy);
        if (theMap[futureY][futureX] == 0) { // if no wall at resultant location
            move(&theBall, dx, dy);
        } else if (theMap[futureY][getX(theBall)] == 0) { // try just moving in y-dir
            move(&theBall, 0, dy);
        } else if (theMap[getY(theBall)][futureX] == 0) { // just moving in x-dir
            move(&theBall, dx, 0);
        } //otherwise, don't move
        if (needsUpdate(theBall)) {
            erase_ball(theBall);
            draw_ball(theBall);
            OrbitOledUpdate();
        }

    
    }
}

void tick() {

}

/*char redraw(){
    //char* newMap =
	return checkWin(getX(theBall),getY(theBall),theMap);
}*/

void logic(){
    char flag = 0;
    
    while(!flag){
        update();
        tick();
        flag = redraw();
    }
}
void printMap(char map[32][128]) {
    int row, col;
	for (row = 0; row < 32; row++) {
		for (col = 0; col < 128; col++) {
			if (map[row][col] == SPACE) {
				printf(" ");
			} else if (map[row][col] == WALL) {
				printf("O");
			} else if (map[row][col] == WIN_POS) {
				printf("K");
			}
			
		}
		printf("\n");
	}
}

