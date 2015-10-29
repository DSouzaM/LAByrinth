extern "C" {
#include <OrbitBoosterPackDefs.h>
#include "led.h"
}

void setup() {
	setup_led();
	Serial.begin(9600);
}

void loop() {
	int i;
	for (i = 0; i < 4; i++) {
		set_led(i, HIGH);
		Serial.write(i+'0');
		delay(100);
	}
	
	for (i = 3; i >= 0; i--) {
		set_led(i, LOW);
		Serial.write(i+'0');
		delay(100);	
	}
}
