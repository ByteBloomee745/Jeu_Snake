#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

struct Player {
    int Score;
    bool lose;
};

void initPlayer(struct Player *player);
void updateScore(struct Player *player, int points);

#endif

