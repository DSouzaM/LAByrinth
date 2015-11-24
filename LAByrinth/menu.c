#include <string.h>
#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include <OrbitOledChar.h>
#include "Energia.h"
#include "display.h"
#include "button.h"

#include "menu.h"

#define HELP_PAGES 4
#define TITLE_ROWS 2
#define INTIAL_LINES 4

const char HELP_TEXT[HELP_PAGES][17] = {"Hi, this game is bullshit. This is a test.", "This is another page.", "The quick brown fox jumps", "LAST PAGE"};
const char TITLE[17] = "LAByrinth";
const char TITLE_TEXT[TITLE_ROWS][17] = {"Start", "Help"};
const char INITIAL_TEXT[INTIAL_LINES][17] = {"BTN1 - toggle", "BTN2 - select", "", "Press to start"};


void help_menu() {
	int page = 0;
	clear_display();
	while (page < HELP_PAGES) {
		clear_display();
		put_string_display(HELP_TEXT[page], 0, 0);
		while (!(get_button(0) || get_button(1)))
			;
		if (get_button(0)) {
			if (--page < 0)
				page = 0;
			while (get_button(0))
				;
		}
		
		if (get_button(1)) {
			++page;
			while (get_button(1))
				;
		}
	}
}

void center_text(const char *s, int row) {
	put_string_display(s, (16 - strlen(s))/2, row);
}

int start_menu() {
	int i;
	int row = 0;
	clear_display();
	center_text(TITLE, 0);
	for (i = 0; i < TITLE_ROWS; i++)
		put_string_display(TITLE_TEXT[i], 5, i+1);
	
	while (1) {
		for (i = 0; i < TITLE_ROWS; i++)
			put_string_display(i == row ? "*" : " ", 3, i+1);
		while (!(get_button(0) || get_button(1)))
			;
		
		if (get_button(0)) {
			row = ++row % TITLE_ROWS;
			while (get_button(0))
				;
		}
		
		if (get_button(1)) {
			while (get_button(1))
				;
			return row;
		}
		
	}
}

void initial_menu() {
	int i;
	clear_display();
	for (i = 0; i < INTIAL_LINES; i++)
		put_string_display(INITIAL_TEXT[i], 0, i);
	while (!(get_button(0) || get_button(1)))
		;
	while (get_button(0) || get_button(1))
		;
}