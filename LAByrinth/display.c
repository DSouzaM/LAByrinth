#include <OrbitOled.h>
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

void display_put_string(const int* string, int x, int y) {
	OrbitOledMoveTo(x, y);
	OrbitOledDrawString(string);
}

void display_put_bitmap(const int bitmap[Y_MAX][X_MAX]) {
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
