#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include <OrbitOledChar.h>
#include "Energia.h"
#include "display.h"

char dot[2] = {3,3};
char empty[2] = {0,0};

void setup_display() {
	OrbitOledInit();
	OrbitOledClear();
}

void clear_display() {
	OrbitOledClear();
}

int get_x_display() {
	int x, y;
	OrbitOledGetPos(&x, &y);
	return x;
}

int get_y_display() {
	int x, y;
	OrbitOledGetPos(&x, &y);
	return y;
}

void put_string_display(const char* string, int x, int y) {
	OrbitOledSetCursor(x, y);
	OrbitOledPutString(string);
}


void put_bitmap_display(const char bitmap[Y_MAX][X_MAX]) {
	int i, j;
	char bmp[Y_MAX/8 * X_MAX] = {0};
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			bmp[(i/8)*X_MAX + j] |= (bitmap[i][j] ? 1 : 0) << (i % 8);
		}
	}
	OrbitOledClear();
	OrbitOledSetCursor(0, 0);
	OrbitOledPutBmp(X_MAX, Y_MAX, bmp);
	OrbitOledUpdate();
}

void erase_ball(Ball theBall) {
	OrbitOledMoveTo(getPrevX(theBall),getPrevY(theBall));
	OrbitOledPutBmp(2,2,empty);

}

void draw_ball(Ball theBall) {
	OrbitOledMoveTo(getX(theBall),getY(theBall));
	OrbitOledPutBmp(2,2,dot);
}
