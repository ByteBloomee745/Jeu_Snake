#ifndef MAP_H
#define MAP_H

struct Map {
    int Width, Height, FruitX, FruitY;
};

void initMap(struct Map *map, int width, int height);
void generateFruit(struct Map *map);

#endif

