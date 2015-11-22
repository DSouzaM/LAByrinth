extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "display.h"
#include "mapgenerator.h"
}

char theMap[32][128] = 
#include "map1.h"
;

void setup() {
	setup_display();
  Serial.begin(9600);
  generateMap(1,theMap);
  for (int i=0; i< 32; i++) {
    for (int j=0; j< 128; j++) {
        Serial.print(theMap[i][j]+'\0');
    }
    Serial.println();
  }

}
void loop() {
	put_string_display("Hello", 0, 0);
}
