#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#include "button.h"

static const int BUTTONPORTS[] = {BTN1Port, BTN2Port};
static const int BUTTONS[] = {BTN1, BTN2};


void setup_button() {
	int i;
	for (i = 0; i < 2; i++) {
		GPIOPinTypeGPIOInput(BUTTONPORTS[i], BUTTONS[i]);
	}
}

int get_button(int button) {
	return GPIOPinRead(BUTTONPORTS[button], BUTTONS[button]);
}
