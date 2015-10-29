#ifndef _LAUNCHPAD_LED_H
#define _LAUNCHPAD_LED_H

#define RED 0
#define GREEN 1
#define BLUE 2

#define NUM_LEDS 3

void setup_launchpad_led();
void digital_set_led(int led, char state);
void analog_set_led(int led, unsigned char state);

#endif
