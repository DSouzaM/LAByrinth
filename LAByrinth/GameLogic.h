#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#define BALL_WIDTH 2
char checkWin (char row, char col, const char map[32][128]);
void setupGame();
void updateGame();
void tick();
char redraw();

#endif