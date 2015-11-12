extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "accelerometer.h"
}

void setup() {
	Serial.begin(9600);
	setup_accelerometer();
}
void loop() {
	char s[0x10];
	sprintf(s, "%4d, %4d, %4d\n", get_accelerometer_x(), get_accelerometer_y(), get_accelerometer_z());
	Serial.write(s);
	delay(200);
}
