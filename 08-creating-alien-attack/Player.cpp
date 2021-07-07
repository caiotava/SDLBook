//
// Created by caiotava on 4/15/21.
//

#include "Player.h"

#include "Game.h"
#include "InputHandler.h"

void Player::update() {
    auto game = Game::Instance();

    if (game->getLevelComplete()) {
        if (position.getX() >= game->getGameWidth()) {
            game->setCurrentLevel(game->getCurrentLevel() + 1);
            return;
        }

        velocity.setX(0);
        velocity.setY(3);

        SDLGameObject::update();
        handleAnimation();
        return;
    }

    if (!dying) {
        velocity.setX(0);
        velocity.setY(0);

        handleInput();

        SDLGameObject::update();

        handleAnimation();
        return;
    }

    currentFrame = int((SDL_GetTicks() / 100) % numFrames);

    if (dyingCounter == dyingTime) {
        resurrect();
    }

    dyingCounter++;
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

    velocity = ((*input->getMousePosition()) - position) / 50;

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

void Player::resurrect() {
    Game::Instance()->setPlayerLives(Game::Instance()->getPlayerLiver() - 1);

    position.setX(10);
    position.setY(200);
    dying = false;

    textureID = "player";

    currentFrame = 0;
    numFrames = 5;
    width = 101;
    height = 46;

    dyingCounter = 0;
    invulnerable = true;
}

void Player::handleAnimation() {
    if (invulnerable) {
        alpha = alpha ^ 255;

        if (invulnerableCounter == invulnerableTime) {
            invulnerable = false;
            invulnerableCounter = 0;
            alpha = 255;
        }

        invulnerableCounter++;
    }

    if (!dead) {
        angle = 0.0;

        if (velocity.getX() < 0) {
            angle = -10.0;
        } else if (velocity.getX() > 0) {
            angle = 10.0;
        }
    }

    currentFrame = int((SDL_GetTicks() / 100) % numFrames);
}