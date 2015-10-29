#ifndef _LAUNCHPAD_LED_H
#define _LAUNCHPAD_LED_H

void setup_launchpad_led();
void digital_set_red_led(char state);
void digital_set_green_led(char state);
void digital_set_blue_led(char state);
void analog_set_red_led(unsigned char state);
void analog_set_green_led(unsigned char state);
void analog_set_blue_led(unsigned char state);

#endif
