#include "Energia.h"
#include "led.h"

Led::Led() {
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(BLUE_LED, OUTPUT);
}

void Led::toggle_red_led(char state) {
	digitalWrite(RED_LED, state ? HIGH : LOW);
}

void Led::toggle_green_led(char state) {
	digitalWrite(GREEN_LED, state ? HIGH : LOW);
}

void Led::toggle_blue_led(char state) {
	digitalWrite(BLUE_LED, state ? HIGH : LOW);
}

void Led::set_red_led(unsigned char state) {
	analogWrite(RED_LED, state);
}

void Led::set_green_led(unsigned char state) {
	analogWrite(GREEN_LED, state);
}

void Led::set_blue_led(unsigned char state) {
	analogWrite(BLUE_LED, state);
}