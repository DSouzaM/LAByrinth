#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#include "switch.h"

static const char SWITCHPORTS[] = {SWT1Port, SWT2Port};
static const char SWITCHES[] = {SWT1, SWT2};

void setup_switch() {
	GPIOPadConfigSet(SWTPort, SWT1 | SWT2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
	GPIOPinTypeGPIOInput(SWTPort, SWT1 | SWT2);
}

char get_switch(char swtch) {
	return GPIOPinRead(SWITCHPORTS[swtch], SWITCHES[swtch]);
}