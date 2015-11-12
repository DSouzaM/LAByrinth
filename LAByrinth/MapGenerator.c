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

char* map1(){
    
}

char* map2(){
    
}

char* map3(){
    
}


char* mapGenerator (int level){
    switch(level) {
    		case 0: return map1();
    		case 1: return map2();
    		default: return map3();
    }
}