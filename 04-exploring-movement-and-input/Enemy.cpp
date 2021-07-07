//
// Created by caiotava on 4/17/21.
//

#include "Enemy.h"

void Enemy::update() {
    position.setX(1);
    position.setY(1);

    currentFrame = int((SDL_GetTicks() / 100) % 6);

    SDLGameObject::update();
}