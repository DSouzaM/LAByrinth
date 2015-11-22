#ifndef BALL_H
#define BALL_H

typedef struct Balls {
	float x;
	float y;
	float prev_x;
	float prev_y;
} Ball;
char getX(Ball theBall);
char getY(Ball theBall);
char getPrevX(Ball theBall);
char getPrevY(Ball theBall);
char getFutureX(Ball theBall, float x);
char getFutureY(Ball theBall, float y);
char needsUpdate(Ball theBall);
void move(Ball *theBall, float x, float y);
void moveTo(Ball *theBall, float x, float y);


#endif
