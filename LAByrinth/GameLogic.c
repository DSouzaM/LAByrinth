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
        dy =scale_accelerometer(get_accelerometer_y());
        char futureX = getFutureX(theBall,dx);
        char futureY = getFutureY(theBall,dy);

        if (theMap[futureY][futureX] == 0 && theMap[futureY][futureX+1] == 0 && theMap[futureY+1][futureX] == 0 && theMap[futureY+1][futureX+1] == 0) { // if no wall at resultant location
            move(&theBall, dx, dy);
        } else if (theMap[futureY][getX(theBall)] == 0 && theMap[futureY][getX(theBall)+1] == 0 && theMap[futureY+1][getX(theBall)] == 0 && theMap[futureY+1][getX(theBall)+1] == 0) { // try just moving in y-dir
            move(&theBall, 0, dy);
        } else if (theMap[getY(theBall)][futureX] == 0 && theMap[getY(theBall)+1][futureX] == 0 && theMap[getY(theBall)][futureX+1] == 0 && theMap[getY(theBall)+1][futureX+1] == 0) { // just moving in x-dir
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


Ball getBall(){
    return theBall;
}
