#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//#include "display.h"
#include "MapGenerator.h"
#include "ball.h"

//checks whether the player has landed on the right spot to win the current game

bool checkWin (char row, char col, const char map[32][128]){
    int checkRow, checkCol;
    for (checkRow = row; checkRow < row + BALL_WIDTH; checkRow++){
    	for (checkCol = col; checkCol < col + BALL_WIDTH; checkCol++) {
    		if (map[checkRow][checkCol] == WIN_POS){
				return true;
    		}
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
    //char* newMap =
	return true;
}

void logic(){
    bool flag = false;
    
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

