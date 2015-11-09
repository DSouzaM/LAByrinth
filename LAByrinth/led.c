#include <OrbitBoosterPackDefs.h>
#include "Energia.h"

#include "led.h"

static const int LEDPORTS[] = {LED1Port, LED2Port, LED3Port, LED4Port};
static const int LEDS[] = {LED1, LED2, LED3, LED4};

void setup_led() {
	int i;
	for (i = 0; i < 4; i++)
		GPIOPinTypeGPIOOutput(LEDPORTS[i], LEDS[i]);
}

void set_led(int led, int state) {
	GPIOPinWrite(LEDPORTS[led], LEDS[led], state ? LEDS[led] : LOW);
}
