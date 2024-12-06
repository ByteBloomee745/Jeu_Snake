#include "map.h"
#include <stdlib.h>
#include <time.h>

void initMap(struct Map *map, int width, int height) {
    map->Width = width;
    map->Height = height;
    generateFruit(map);
}

void generateFruit(struct Map *map) {
    srand(time(NULL));
    map->FruitX = rand() % (map->Width - 2) + 1;
    map->FruitY = rand() % (map->Height - 2) + 1;
}

