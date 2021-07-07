//
// Created by caiotava on 4/15/21.
//

#include "Player.h"

void Player::update() {
    x--;
    currentFrame = SDL_GetTicks() / 100 % 6;
}
