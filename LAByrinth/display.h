#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "Energia.h"
#include "ball.h"
#define X_MAX 128
#define Y_MAX 32
#define LETTER_WIDTH 8
#define LETTER_HEIGHT 8

void setup_display();
void clear_display();
int get_x_display();
int get_y_display();
void put_string_display(const char* string, int x, int y);
void put_bitmap_display(const char bitmap[Y_MAX][X_MAX]);
void erase_ball(Ball theBall);
void draw_ball(Ball theBall);

#endif