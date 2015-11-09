#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "Energia.h"

#define X_MAX 128
#define Y_MAX 32

void display_setup();
void display_clear();
int display_get_x();
int display_get_y();
void display_put_string(const int* string, int x, int y);
void display_put_bitmap(const int bitmap[Y_MAX][X_MAX]);

#endif