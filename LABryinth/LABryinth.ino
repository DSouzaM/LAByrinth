extern "C"{
#include "launchpad_led.h"
}

void setup() {
	setup_led();
}

void loop() {
	toggle_red_led(1);
	delay(500);
	toggle_red_led(0);
	delay(500);
}
