#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

static const int LEDPorts[] = {LED1Port, LED2Port, LED3Port, LED4Port};
static const int LEDS[] = {LED1, LED2, LED3, LED4};

void setup_led() {
	int i;
	for (i = 0; i < 4; i++)
		  GPIOPinTypeGPIOOutput(LEDPorts[i], LEDS[i]);
}

void set_led(int led, char state) {
	GPIOPinWrite(LEDPorts[led], LEDS[led], state ? HIGH : LOW);
}
