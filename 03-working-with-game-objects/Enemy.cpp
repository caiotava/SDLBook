//
// Created by caiotava on 4/17/21.
//

#include "Enemy.h"

void Enemy::update() {
    y += 1;
    x += 1;

    currentFrame = int((SDL_GetTicks() / 100) % 6);
}