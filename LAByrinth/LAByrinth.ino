extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "display.h"
}

char bmp[Y_MAX][X_MAX];

void setup() {
	int i, j;
	Serial.begin(9600);
	for (i = 0; i < Y_MAX; i++)
		for (j = 0; j < X_MAX; j++)
			bmp[i][j] = (i+j) % 2;
	display_setup();
}
void loop() {
	display_put_bitmap(bmp);
	delay(10);
}
