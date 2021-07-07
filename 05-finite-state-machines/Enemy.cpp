//
// Created by caiotava on 4/17/21.
//

#include "Enemy.h"

Enemy::Enemy(LoaderParams* params) : SDLGameObject(params) {
    velocity.setY(2);
    velocity.setX(0.001);
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