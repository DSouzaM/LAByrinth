extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "display.h"
}

void setup() {
	display_setup();
}
void loop() {
	display_put_string("Hello", 0, 0);
}
