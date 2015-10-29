extern "C"{
#include "led.h"
}

void setup() {
	setup_led();
}

void loop() {
	for (int i = 0; i < 4; i++) {
		set_led(i, HIGH);
		delay(10);
	}
	
	for (int i = 3; i >= 0; i--) {
		set_led(i, LOW);
		delay(10);	
	}
}
