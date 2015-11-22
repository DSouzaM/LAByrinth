#include <math.h>
#include "ball.h"

char getX(Ball theBall){
	return (char) lroundf(theBall.x);
}
char getY(Ball theBall){
	return (char) lroundf(theBall.y);
}
char getPrevX(Ball theBall){
	return (char) lroundf(theBall.prev_x);
}
char getPrevY(Ball theBall){
	return (char) lroundf(theBall.prev_y);
}
char getFutureX(Ball theBall, float x){
	return (char) lroundf(theBall.x + x);
}
char getFutureY(Ball theBall, float y){
	return (char) lroundf(theBall.y + y);
}

char needsUpdate(Ball theBall) {
	return (getX(theBall) != getPrevX(theBall) || getY(theBall) != getPrevY(theBall)); //returns 1 if the position on the screen needs to change
}
void move(Ball *theBall, float x, float y){
	theBall->prev_x = theBall->x;
	theBall->prev_y = theBall->y;
	theBall->x = theBall->x + x;
	theBall->y = theBall->y + y;
}
void moveTo(Ball *theBall, float x, float y) {
	theBall->prev_x = theBall->x;
	theBall->prev_y = theBall->y;
	theBall->x = x;
	theBall->y = y;
}
