extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "display.h"
#include "MapGenerator.h"
#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include <OrbitOledChar.h>
#include "ball.h"
#include "switch.h"
#include "potentiometer.h"
#include "button.h"
#include "menu.h"
}
char theMap[32][128] = {{0}};
long start;
float dx, dy;
Ball theBall;
int fps;

char theMap[32][128] = 
#include "map1.h"
;

void setup() {
	int game_not_started = 1;
	setup_display();
	setup_button();
	setup_switch();
	setup_potentiometer();
	fps = 1 + get_potentiometer()/30;
	theBall.prev_x = 0;
	theBall.prev_y = 0;
	theBall.x = 4;
	theBall.y = 4;

	Serial.begin(9600);
	generateMap(0,theMap);
	/*for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 128; j++) {
			Serial.print(theMap[i][j]+'\0');
		}
		Serial.println();
	}*/
	
	initial_menu();
	while (game_not_started) {
		switch (start_menu()) {
			case 0:
				game_not_started = 0;
				break;
			case 1:
				help_menu();
				break;
		}
	}
	
	put_bitmap_display(theMap);
	
	start = millis();

}

void loop() {
	long now = millis();
	fps = 1 + get_potentiometer()/30;

	if (now - start >(1000/fps)) {
		start = now;	
		dx = 0.5 - get_switch(0); // read from accelerometer
		dy = 0.5 - get_switch(1); // read from accelerometer
		
		/*Serial.println(getPrevX(theBall) +'\0');
		Serial.println(getPrevY(theBall) +'\0');
		Serial.println(getX(theBall) +'\0');
		Serial.println(getY(theBall) +'\0');
		Serial.println(theBall.x +'\0');
		Serial.println(theBall.y +'\0');
		
		Serial.println(getFutureX(theBall,dx) + '\0');
		Serial.println(getFutureY(theBall,dy) + '\0');
		Serial.println("-------------------");
		*/
		char futureX = getFutureX(theBall,dx);
		char futureY = getFutureY(theBall,dy);
		if (theMap[futureY][futureX] == 0) { // if no wall at resultant location
			move(&theBall, dx, dy);
		} else if (theMap[futureY][getX(theBall)] == 0) { // try just moving in y-dir
			move(&theBall, 0, dy);
		} else if (theMap[getY(theBall)][futureX] == 0) { // just moving in x-dir
			move(&theBall, dx, 0);
		} //otherwise, don't move
		if (needsUpdate(theBall)) {
			Serial.println("Updating");
			erase_ball(theBall);
			draw_ball(theBall);
			OrbitOledUpdate();
		}

	
	}
}
