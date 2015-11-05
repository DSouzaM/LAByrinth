#ifndef  _LED_H
#define _LED_H
#include "OrbitBoosterPackDefs.h"
#include "Energia.h"



static const int Orbit_BTN1 = PD_2;    // Orbit Button 1
static const int Orbit_BTN2 = PE_0;    // Orbit Button 2

void setup_led();
void set_led(int led, char state);
int get_led(int led);

#endif