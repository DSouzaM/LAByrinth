#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#include "potentiometer.h"

void setup_potentiometer() { 
	// Try to figure out the boosterpack way of doing this
	// This code doesn't do anything right now. It's just decorative.
	pinMode(AIN, INPUT); 
}

int get_potentiometer() {
	// I have no idea where this magic number address comes from
	return analogRead(0x2D);
}