extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "display.h"
}

void setup() {
	setup_display();
}
void loop() {
	put_string_display("Hello", 0, 0);
}
