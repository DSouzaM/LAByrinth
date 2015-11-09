#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#include "switch.h"

static const int SWITCHES[] = {SWT1, SWT2};

void setup_switch() {
	GPIOPinTypeGPIOInput(SWTPort, SWT1 | SWT2);
}

int get_switch(int swtch) {
	return GPIOPinRead(SWTPort, SWITCHES[swtch]);
}