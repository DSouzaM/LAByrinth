#include <OrbitBoosterPackDefs.h>
#include "Energia.h"
#include "led.h"

static const char LEDPORTS[] = {LED1Port, LED2Port, LED3Port, LED4Port};
static const char LEDS[] = {LED1, LED2, LED3, LED4};

void setup_led() {
	int i;
	for (i = 0; i < 4; i++) {
		GPIOPadConfigSet(LEDPORTS[i], LEDS[i], GPIO_STRENGTH_8MA_SC, GPIO_PIN_TYPE_STD);
		GPIOPinTypeGPIOOutput(LEDPORTS[i], LEDS[i]);
	}
}

void set_led(char led, char state) {
	GPIOPinWrite(LEDPORTS[led], LEDS[led], state ? LEDS[led] : LOW);
}

char get_led(char led) {
	return (GPIOPinRead(LEDPORTS[led], LEDS[led]) != 0);
}


