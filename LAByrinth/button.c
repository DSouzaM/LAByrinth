#include <OrbitBoosterPackDefs.h>
#include "Energia.h"
#include "button.h"

static const char BUTTONPORTS[] = {BTN1Port, BTN2Port};
static const char BUTTONS[] = {BTN1, BTN2};


void setup_button() {
	
  	pinMode(PD_2, INPUT_PULLUP);     
  	pinMode(PE_0, INPUT_PULLUP);
	int i;
	for (i = 0; i < 2; i++) {
		GPIOPadConfigSet(BUTTONPORTS[i], BUTTONS[i], GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
		GPIOPinTypeGPIOInput(BUTTONPORTS[i], BUTTONS[i]);
	}
}

char get_button(char button) {
	return (GPIOPinRead(BUTTONPORTS[button], BUTTONS[button]) != 0);
}
