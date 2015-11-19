#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "Energia.h"

#define X_MAX 128
#define Y_MAX 32

void setup_display();
void clear_display();
int get_x_display();
int get_y_display();
void put_string_display(const char* string, int x, int y);
void put_bitmap_display(const int bitmap[Y_MAX][X_MAX]);

#endif