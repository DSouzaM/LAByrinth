extern "C" {
	#include "OrbitBoosterPackDefs.h"
	#include <OrbitOled.h>
	#include <OrbitOledGrph.h>
	#include <OrbitOledChar.h>
	#include "display.h"
	#include "ball.h"
	#include "switch.h"
	#include "potentiometer.h"
	#include "button.h"
	#include "accelerometer.h"	
	#include "menu.h"
	#include "GameLogic.h"
	#include "MapGenerator.h"
}

const char INITIAL_STATE = 0;
const char MENU_STATE = 1;
const char HELP_STATE = 2;
const char GAME_STATE = 3;
char state;

void setup() {

	setup_display();
	setup_button();
	setup_switch();
	setup_potentiometer();
	setup_accelerometer();

	Serial.begin(9600);
	state = INITIAL_STATE;
	initial_menu();
}
void loop() {
	if (state == INITIAL_STATE) {
		if (get_button(0) || get_button(1)) {
			while (get_button(0) || get_button(1))
				;
			state = MENU_STATE;
			Serial.println("Entering Menu State");
			start_menu();
		}
	} 

	else if (state == MENU_STATE) {
		if (get_button(0)) {
			while (get_button(0))
				;
			next_start_option();		
		}		
		if (get_button(1)) {
			while (get_button(1))
				;
			switch (get_start_selection()){
				case 0:
					state = GAME_STATE;
					Serial.println("Entering Game State");
					setLevel(0);
					setupGame();
					break;
				case 1:
					state = HELP_STATE;
					Serial.println("Entering Help State");
					help_menu();
					break;
			}
		}
	} 

	else if (state == HELP_STATE) {
		if (get_button(0)) {
			delay(20);
			while (get_button(0))
				;
			next_help_page();
		}
		
		if (get_button(1)) {
			delay(20);
			while (get_button(1))
				;
			state = MENU_STATE;
			Serial.println("Entering Menu State");
			start_menu();
		}
	} else if (state == GAME_STATE) {
			updateGame();
			/*if (checkOn(PITFALL)){
				char msg[64];
				sprintf(msg, "LEVEL %d FAILED  AVOID PITFALLS! PRESS ANY BUTTON TO CONTINUE",getLevel()+1);
				pause_menu(msg);
				state = MENU_STATE;
				start_menu();	
			} else */if (checkOn(WIN_POS)) {
				int lvl = getLevel();
				if (lvl+1 < NUM_MAPS) {// lvl 0, lvl 1 -> NUM_MAPS = 2
					char msg[64];
					sprintf(msg, "LEVEL %d COMPLETEPRESS ANY BUTTON TO CONTINUE",lvl+1);
					pause_menu(msg);
					setLevel(lvl+1);
					setupGame();
				} else {
					char msg[64];
					sprintf(msg, "CONGRATULATIONS! YOU WON!");
					pause_menu(msg);
					state = MENU_STATE;
					Serial.println("Entering Menu State");

					start_menu();
				}
			}
	}
}
