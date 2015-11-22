#include <OrbitOled.h>
#include <OrbitOledGrph.h>
#include <OrbitOledChar.h>
#include "Energia.h"
#include "display.h"
#include "button.h"

#include "menu.h"

#define HELP_PAGES 4

const char help_text[HELP_PAGES][64] = {"Hi, this game is bullshit. This is a test.", "This is another page.", "The quick brown fox jumps", "LAST PAGE"};

void help_menu() {
	int page = 0;
	while (page < HELP_PAGES) {
		clear_display();
		put_string_display(help_text[page], 0, 0);
		while (!(get_button(0) || get_button(1)))
			;
		if (get_button(0)) {
			++page;
			while (get_button(0))
				;
		}
		
		if (get_button(1)) {
			if (--page < 0)
				page = 0;
			while (get_button(1))
				;
		}
	}
}
