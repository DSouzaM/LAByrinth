#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
extern const char SPACE, WALL, BALL, PITFALL, WIN_POS, WIDTH, LENGTH, NUM_MAPS;
void generateMap(int level, char map[32][128]);
#endif
