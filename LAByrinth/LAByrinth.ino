extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "button.h"
#include "led.h"
}

void setup() {
	setup_led();
	setup_button();
}
void loop() {
	int i;
	for (i = 0; i < 4; i++)
		set_led(i, 0);
	set_led((get_button(1) ? 2 : 0) + (get_button(0) ? 1 : 0), 1);
}
