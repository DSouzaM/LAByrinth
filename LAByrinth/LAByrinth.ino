extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "button.h"
#include "led.h"
#include "switch.h"
}

void setup() {
	setup_led();
	setup_button();
}
void loop() {
	set_led(0, get_button(0)); 
	set_led(1, get_button(1)); 
	set_led(2, get_switch(0)); 
	set_led(3, get_switch(1)); 
}
