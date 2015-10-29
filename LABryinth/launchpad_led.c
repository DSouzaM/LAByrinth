#include "Energia.h"
#include "launchpad_led.h"

void setup_launchpad_led() {
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(BLUE_LED, OUTPUT);
}

void digital_set_red_led(char state) {
	digitalWrite(RED_LED, state ? HIGH : LOW);
}

void digital_set_green_led(char state) {
	digitalWrite(GREEN_LED, state ? HIGH : LOW);
}

void digital_set_blue_led(char state) {
	digitalWrite(BLUE_LED, state ? HIGH : LOW);
}

void analog_set_red_led(unsigned char state) {
	analogWrite(RED_LED, state);
}

void analog_set_green_led(unsigned char state){
	analogWrite(GREEN_LED, state);
}

void analog_set_blue_led(unsigned char state) {
	analogWrite(BLUE_LED, state);
}