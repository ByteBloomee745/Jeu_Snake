#include "snake.h"

void initSnake(struct Snake *snake, int startX, int startY) {
    snake->HeadX = startX;
    snake->HeadY = startY;
    snake->TailLength = 0;
    snake->Dir = Right;
}

void moveSnake(struct Snake *snake) {
    // Déplacement de la queue
    int i ;
    for ( i = snake->TailLength - 1; i > 0; i--) {
        snake->TailX[i] = snake->TailX[i - 1];
        snake->TailY[i] = snake->TailY[i - 1];
    }
    if (snake->TailLength > 0) {
        snake->TailX[0] = snake->HeadX;
        snake->TailY[0] = snake->HeadY;
    }

    // Déplacement de la tête
    switch (snake->Dir) {
        case Top: 
            snake->HeadY--; 
            break;
        case Down: 
            snake->HeadY++; 
            break;
        case Right: 
            snake->HeadX++; 
            break;
        case Left: 
            snake->HeadX--; 
            break;
    }
}

bool checkCollision(struct Snake *snake, struct Map *map) {
	int i ;
    // Collision avec les murs
    if (snake->HeadX <= 0 || snake->HeadX >= map->Width - 1 ||
        snake->HeadY <= 0 || snake->HeadY >= map->Height - 1) {
        return true;
    }

    // Collision avec la queue
    for ( i = 0; i < snake->TailLength; i++) {
        if (snake->HeadX == snake->TailX[i] && snake->HeadY == snake->TailY[i]) {
            return true;
        }
    }

    return false;
}

bool eatFruit(struct Snake *snake, struct Map *map) {
    if (snake->HeadX == map->FruitX && snake->HeadY == map->FruitY) {
        return true;
    }
    return false;
}

