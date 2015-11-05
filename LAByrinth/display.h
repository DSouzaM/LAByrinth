#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "Energia.h"

#define X_MAX 128
#define Y_MAX 32

void display_setup();
void display_clear();
int display_get_x();
int display_get_y();
void display_write_string(const char* string, int x, int y);
void display_put_bitmap(const char bitmap[X_MAX][Y_MAX]);

#endif