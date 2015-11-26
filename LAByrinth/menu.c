#include <string.h>
#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include <OrbitOledChar.h>
#include "Energia.h"
#include "display.h"
#include "button.h"
#include "menu.h"

char HELP_TEXT[HELP_PAGES][4][17] = {
	{"Welcome to", "LAByrinth! Use", "BTN1 to scroll,", "BTN2 to return"}, 
	{"Try to reach the", "end. Tilt to", "control the", "ball."},
	{"Twist the knob", "to control the", "speed.", ""},
	{"Each level gets", "harder.", "", "Have fun!"}
};
char TITLE[17] = "LAByrinth";	
char TITLE_TEXT[TITLE_ROWS][17] = {"Start", "Help"};
char INITIAL_TEXT[INITIAL_LINES][17] = {"BTN1 - toggle", "BTN2 - select", "", "Press to start"};

char start_menu_selection;
char page;

void help_menu() {
	page = -1;
	next_help_page();
}
void next_help_page() {
	int i;
	page = ++page % HELP_PAGES;
	clear_display();
	for (i = 0; i < 4; i++)
		put_string_display(HELP_TEXT[page][i], 0, i);
}

void center_text(const char *s, int row) {
	put_string_display(s, (16 - strlen(s))/2, row);
}

void start_menu() {
	int i;
	clear_display();
	center_text(TITLE, 0);
	for (i = 0; i < TITLE_ROWS; i++)
		put_string_display(TITLE_TEXT[i], 5, i+1);
	
	start_menu_selection = 0;
	put_string_display("*", 3, 1);
}
void next_start_option() {
	start_menu_selection = ++start_menu_selection % TITLE_ROWS;
	int i;
	for (i = 0; i < TITLE_ROWS; i++)
				put_string_display(i == start_menu_selection ? "*" : " ", 3, i+1);
}
char get_start_selection() {
	return start_menu_selection;
}

void initial_menu() {
	int i;
	clear_display();
	for (i = 0; i < INITIAL_LINES; i++)
		put_string_display(INITIAL_TEXT[i], 0, i);
}

void pause_menu(const char *s) {
	clear_display();
	put_string_display(s, 0, 0);
	while (!(get_button(0) || get_button(1)))
		while (get_button(0) || get_button(1))
			;
}
		