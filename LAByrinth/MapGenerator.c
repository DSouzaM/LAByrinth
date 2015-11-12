#include <math.h>

//defines a numerical value for all elements within the maze
const char SPACE = 0;
const char WALL = 1;
const char BALL = 2;
const char PITFALL = 3;
const char WIN_POS = 4;

//defines the size of the screen
const char WIDTH = 32;
const char LENGTH = 128;

void map1(char map[32][128]){

	for (int row = 0; row < 32; row++) {
		for (int col = 0; col < 128; col++) {
			map[row][col] = 0;
		}
		map[row][0] = WALL;
		map[row][127] = WALL;
		map[row][row] = WALL;
	}
	for (int col = 0; col < 128; col++) {
		map[0][col] = WALL;
		map[31][col] = WALL;
	}
}
/*
char** map2(){
    
}

char** map3(){
    
}
*/

void mapGenerator (int level, char map[32][128]){
	map1(map);
	/*
    switch(level) {
    		case 0: return map1();
    		case 1: return map2();
    		default: return map3();
    }*/
}