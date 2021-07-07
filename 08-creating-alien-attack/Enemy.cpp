//
// Created by caiotava on 4/17/21.
//

#include "Enemy.h"

void Enemy::load(const LoaderParams *params) {
    SDLGameObject::load(params);

    velocity.setY(2);
}

void Enemy::update() {
    currentFrame = int((SDL_GetTicks() / 100) % 5);

    if (position.getY() < 0) {
        velocity.setY(2);
    } else if (position.getY() > 600) {
        velocity.setY(-2);
    }

    SDLGameObject::update();
}