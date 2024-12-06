#include "player.h"

void initPlayer(struct Player *player) {
    player->Score = 0;
    player->lose = false;
}

void updateScore(struct Player *player, int points) {
    player->Score += points;
}

