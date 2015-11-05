#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

#include "Energia.h"
#include "display.h"

void display_setup() {
	OrbitOledInit();
}

void display_clear() {
	OrbitOledClear();
}

int display_get_x() {
	int x, y;
	OrbitOledGetPos(&x, &y);
	return x;
}

int display_get_y() {
	int x, y;
	OrbitOledGetPos(&x, &y);
	return y;
}

void display_write_string(const char* string, int x, int y) {
	OrbitOledSetCursor(x, y);
	OrbitOledPutString(string);
}

void display_put_bitmap(const char bitmap[X_MAX][Y_MAX]) {
	int i, j;
	char bmp[X_MAX/8][Y_MAX] = {0};
	for (i = 0; i < X_MAX; i++) {
		for (j = 0; j < Y_MAX; j++)
			bmp[i/8][j] |= (bitmap[i][j] ? 1 : 0) << i % 8;
	}
	OrbitOledSetCursor(0, 0);
	OrbitOledPutBmp(X_MAX, Y_MAX, bitmap);
}
	
