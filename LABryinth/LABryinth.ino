#include "led.h"

Led led;

void setup() {
	// insert code here
}

void loop() {
	led.toggle_red_led(1);
	delay(500);
	led.toggle_green_led(1);
	delay(500);
	led.toggle_blue_led(1);
	delay(500);
	led.toggle_red_led(0);
	delay(500);
	led.toggle_green_led(0);
	delay(500);
	led.toggle_blue_led(0);
	delay(500);
}
