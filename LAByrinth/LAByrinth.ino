extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "accelerometer.h"
}

void setup() {
	Serial.begin(9600);
	setup_accelerometer();
}
void loop() {
	Serial.println(get_accelerometer_x());
	delay(200);
}
