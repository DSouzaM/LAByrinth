#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//#include "display.h"
#include "MapGenerator.h"

//checks whether the player has landed on the right spot to win the current game
/*bool checkWin (char[2]){
	 if (
}*/

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
	for (int row = 0; row < 32; row++) {
		for (int col = 0; col < 128; col++) {
			if (map[row][col] == 0) {
				printf(" ");
			} else if (map[row][col] == 1) {
				printf("O");
			}
		}
		printf("\n");
	}
}


int main() {
	char map[32][128];
	mapGenerator(0,map);
	printMap(map);
	return 1;
}