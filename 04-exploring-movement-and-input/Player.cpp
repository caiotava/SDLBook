//
// Created by caiotava on 4/15/21.
//

#include "Player.h"
#include "InputHandler.h"

void Player::update() {
    velocity.setX(0);
    velocity.setY(0);

    handleInput();

    currentFrame = SDL_GetTicks() / 100 % 6;

    SDLGameObject::update();
}

void Player::handleInput() {
    auto *input = InputHandler::Instance();

    if (input->isKeyDown(SDL_SCANCODE_RIGHT)) {
        velocity.setX(2);
    }

    if (input->isKeyDown(SDL_SCANCODE_LEFT)) {
        velocity.setX(-2);
    }

    if (input->isKeyDown(SDL_SCANCODE_UP)) {
        velocity.setY(-2);
    }

    if (input->isKeyDown(SDL_SCANCODE_DOWN)) {
        velocity.setY(2);
    }

    if (input->getMouseButtonState(LEFT)) {
        velocity.setX(1);
    }

    if (input->getMouseButtonState(RIGHT)) {
        velocity = ((*input->getMousePosition()) - position) / 100;
    }

    if (!input->isJoysticksInitialised()) {
        return;
    }

    if (input->getButtonState(0, 3)) {
        velocity.setX(1);
    }

    if (input->xvalue(0, 1) > 0 || input->xvalue(0, 1) < 0) {
        velocity.setX(1 * input->xvalue(0, 1));
    }

    if (input->yvalue(0, 1) > 0 || input->yvalue(0, 1) < 0) {
        velocity.setY(1 * input->yvalue(0, 1));
    }

    if (input->xvalue(0, 2) > 0 || input->xvalue(0, 2) < 0) {
        velocity.setX(1 * input->xvalue(0, 2));
    }

    if (input->yvalue(0, 2) > 0 || input->yvalue(0, 2) < 0) {
        velocity.setY(1 * input->yvalue(0, 2));
    }
}