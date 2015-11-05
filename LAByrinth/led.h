#ifndef _LED_H
#define _LED_H

#include "OrbitBoosterPackDefs.h"
#include "Energia.h"

void set_led(char led, char state);
char get_led(char led);

#endif