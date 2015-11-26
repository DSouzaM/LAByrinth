#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#define BALL_WIDTH 2
int checkOn (char value);
void setupGame();
void updateGame();
double getAcclX();
double getAcclY();
void setLevel(int lvl);
int getLevel();

#endif