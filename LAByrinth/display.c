#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include "Energia.h"

#include "display.h"

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
	OrbitOledMoveTo(x, y);
	OrbitOledDrawString(string);
}

void put_bitmap_display(const int bitmap[Y_MAX][X_MAX]) {
	int i, j;
	int *s;
	int bmp[Y_MAX/8 * X_MAX] = {0};
	for (i = 0; i < Y_MAX; i++) {
		for (j = 0; j < X_MAX; j++) {
			bmp[(i/8)*X_MAX + j] |= (bitmap[i][j] ? 1 : 0) << (i % 8);
		}
	}
	OrbitOledClear();
	OrbitOledMoveTo(0, 0);
	OrbitOledPutBmp(X_MAX, Y_MAX, bmp);
	OrbitOledUpdate();
}
