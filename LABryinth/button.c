#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

static const int BUTTONPORTS[] = {BTN1Port, BTN2Port};
static const int BUTTONS[] = {BTN1, BTN2};

void setup_button() {
	int i;
	for (i = 0; i < 2; i++) {
		GPIOPadConfigSet(BUTTONPORTS[i], BUTTONS[i], GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
		GPIOPinTypeGPIOInput(BUTTONPORTS[i], BUTTONS[i]);
	}
}

char get_button(int button) {
	return BUTTONS[button] == GPIOPinRead(BUTTONPORTS[button], BUTTONPORTS[button]);
}