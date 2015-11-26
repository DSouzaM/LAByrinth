#include <stdio.h>
#include "display.h"
#include "MapGenerator.h"
#include "ball.h"
#include "GameLogic.h"
#include "accelerometer.h"
#include "math.h"

long start;
char theMap[32][128] = {{0}};
float dx, dy;
Ball theBall;
int fps;
int level;

//checks whether the player has landed on the right spot to win the current game

int checkOn(char value) {
    int x;
    int y;
    for (x = getX(theBall); x <= getX(theBall) + 1; x++){
    	for (y = getY(theBall); y <= getY(theBall) + 1; y++) {
    		if (theMap[y][x] == value){
				return 1;
    		}
    	}
    }
    return 0;
}
void setLevel(int lvl) {
    level = lvl;
}
int getLevel() {
    return level;
}



void setupGame() {
    fps = 1 + get_potentiometer()/30;
    theBall.prev_x = 4;
    theBall.prev_y = 28;
    theBall.x = 4;
    theBall.y = 28;

    generateMap(level,theMap);


    put_bitmap_display(theMap);
    draw_ball(theBall);
    start = millis();
}

double scale_accelerometer(int accelerometer_reading) {
    if (accelerometer_reading < 0) {
        return fmax(-0.8, accelerometer_reading/250.0);
    }
    return fmin(0.8, accelerometer_reading/250.0);

}
double getAcclX(){
    return scale_accelerometer(get_accelerometer_x());
}
double getAcclY(){
    return scale_accelerometer(get_accelerometer_y());
}

//reads and changes the player's position from the input from the accelerometer
void updateGame() {
    long now = millis();
    fps = 1 + get_potentiometer()/30;

    if (now - start >(1000/fps)) {
        start = now;    
        dx = -1*scale_accelerometer(get_accelerometer_x());
        dy = scale_accelerometer(get_accelerometer_y());
        char futureX = getFutureX(theBall,dx);
        char futureY = getFutureY(theBall,dy);

        if (theMap[futureY][futureX] != 1 && theMap[futureY][futureX+1] != 1 && theMap[futureY+1][futureX] != 1 && theMap[futureY+1][futureX+1] != 1) { // if no wall at resultant location
            move(&theBall, dx, dy);
        } else if (theMap[futureY][getX(theBall)] != 1 && theMap[futureY][getX(theBall)+1] != 1 && theMap[futureY+1][getX(theBall)] != 1 && theMap[futureY+1][getX(theBall)+1] != 1) { // try just moving in y-dir
            move(&theBall, 0, dy);
        } else if (theMap[getY(theBall)][futureX] != 1 && theMap[getY(theBall)+1][futureX] != 1 && theMap[getY(theBall)][futureX+1] != 1 && theMap[getY(theBall)+1][futureX+1] != 1) { // just moving in x-dir
            move(&theBall, dx, 0);
        } //otherwise, don't move
        if (needsUpdate(theBall)) {
            erase_ball(theBall);
            draw_ball(theBall);
            OrbitOledUpdate();
        }

    
    }
}


/*char redraw(){
    //char* newMap =
	return checkWin(getX(theBall),getY(theBall),theMap);
}*/

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
