#include <math.h>

//defines a numerical value for all elements within the maze
const char SPACE = 0;
const char WALL = 1;
const char BALL = 2;
const char PITFALL = 3;
const char WIN_POS = 4;
const char NUM_MAPS = 4;

//defines the size of the screen
const char WIDTH = 32;
const char LENGTH = 128;

void map1(char map[32][128]){
	char map1[32][128] = 
	#include "pushmap.h"
	;
	int i,j;
	for (i = 0; i < 32; i++){
		for (j = 0; j < 128; j++){
			map[i][j] = map1[i][j];
		}
	}
}

void map2(char map[32][128]){
	char map2[32][128] = 
	#include "map1.h"
	;
	int i,j;
	for (i = 0; i < 32; i++){
		for (j = 0; j < 128; j++){
			map[i][j] = map2[i][j];
		}
	}
}

void map3(char map[32][128]){
	char map3[32][128] = 
	#include "map2.h"
	;
	int i,j;
	for (i = 0; i < 32; i++){
		for (j = 0; j < 128; j++){
			map[i][j] = map3[i][j];
		}
	}
}

void map4(char map[32][128]){
	char map3[32][128] = 
	#include "map3.h"
	;
	int i,j;
	for (i = 0; i < 32; i++){
		for (j = 0; j < 128; j++){
			map[i][j] = map3[i][j];
		}
	}
}

void generateMap (int level, char map[32][128]){

    switch(level) {
    		case 0: 
    			map1(map);
    			break;
    		case 1: 
    			map2(map);
    			break;
    		case 2: 
    			map3(map);
    			break;
    		case 3:
    			map4(map);
    			break;
    		default:
    			map1(map);
    			break;
    }
}