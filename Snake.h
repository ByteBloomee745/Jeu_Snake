#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>
#include "map.h"

// Directions
enum Direction { Top, Down, Right, Left };

struct Snake {
    int HeadX, HeadY;
    int TailX[100], TailY[100];
    int TailLength;
    enum Direction Dir;
};

void initSnake(struct Snake *snake, int startX, int startY);
void moveSnake(struct Snake *snake);
bool checkCollision(struct Snake *snake, struct Map *map);
bool eatFruit(struct Snake *snake, struct Map *map);

#endif

