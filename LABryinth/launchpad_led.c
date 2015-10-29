#include "Energia.h"
#include "launchpad_led.h"

#define NUM_LEDS 3

static leds[NUM_LEDS];

void setup_launchpad_led() {
	int i;
	
	leds[RED] = RED_LED;
	leds[GREEN] = GREEN_LED;
	leds[BLUE] = BLUE_LED;
	
	for (i = 0; i < NUM_LEDS; i++)
		pinMode(leds[i], OUTPUT);
}

void digital_set_led(int led, char state) {
	digitalWrite(leds[led], state ? HIGH : LOW);
}

void analog_set_led(int led, unsigned char state) {
	analogWrite(leds[led], state);
}