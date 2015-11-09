extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "accelerometer.h"
}

int i = 0;

extern "C" {
void test(char const *s) {
	Serial.write(s);
}
}

void setup() {
	Serial.begin(9600);
	setup_accelerometer();
}
void loop() {
	get_accelerometer_x();
}
