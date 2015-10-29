#ifndef _LED_H
#define _LED_H

#include "Energia.h"

class Led {
	public:
		Led();
		void toggle_red_led(char state);
		void toggle_green_led(char state);
		void toggle_blue_led(char state);
		void set_red_led(unsigned char state);
		void set_green_led(unsigned char state);
		void set_blue_led(unsigned char state);
};

#endif
