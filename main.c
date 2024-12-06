#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "map.h"
#include "snake.h"
#include "player.h"

struct Map map;
struct Snake snake;
struct Player player;

void drawGame() {
	int i, j, k;
    system("cls");
    for ( i = 0; i < map.Height; i++) {
        for ( j = 0; j < map.Width; j++) {
            if (i == 0 || i == map.Height - 1 || j == 0 || j == map.Width - 1) {
                printf("*");
            } else if (i == snake.HeadY && j == snake.HeadX) {
                printf("O");
            } else if (i == map.FruitY && j == map.FruitX) {
                printf("$");
            } else {
                bool printed = false;
                for ( k = 0; k < snake.TailLength; k++) {
                    if (i == snake.TailY[k] && j == snake.TailX[k]) {
                        printf("o");
                        printed = true;
                        break;
                    }
                }
                if (!printed) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", player.Score);
}

void input() {
    if (_kbhit()) {
        char c = _getch();
        switch (c) {
            case 'w': if (snake.Dir != Down) snake.Dir = Top; break;
            case 's': if (snake.Dir != Top) snake.Dir = Down; break;
            case 'd': if (snake.Dir != Left) snake.Dir = Right; break;
            case 'a': if (snake.Dir != Right) snake.Dir = Left; break;
            case 'x': player.lose = true; break;
        }
    }
}

int main() {
    initMap(&map, 40, 20);
    initSnake(&snake, map.Width / 2, map.Height / 2);
    initPlayer(&player);

    while (!player.lose) {
        drawGame();
        input();
        moveSnake(&snake);

        if (checkCollision(&snake, &map)) {
            player.lose = true;
        }

        if (eatFruit(&snake, &map)) {
            generateFruit(&map);
            updateScore(&player, 10);
            snake.TailLength++;
        }

        Sleep(100);
    }

    printf("Game Over! Final Score: %d\n", player.Score);
    return 0;
}

