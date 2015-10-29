extern "C" {
#include <OrbitBoosterPackDefs.h>
#include "led.h"
#include "button.h"
}
	

void setup() {
	setup_led();
	setup_button();
	Serial.begin(9600);
}

void loop() {
	if (get_button(0))
		Serial.write('0');
	if (get_button(1))
		Serial.write('1');
}
