#include<SDL2/SDL.h>
#include"Player.h"
#include"InputHandler.h"

Player::Player(const LoaderParams *pParams): SDLGameObject(pParams)
{
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    velocity.setX(0);
    velocity.setY(0);

    handleInput();

    currentFrame = int((SDL_GetTicks() / 100) % 6);

    SDLGameObject::update();
}

void Player::handleInput()
{
    InputHandler *inputHandler = TheInputHandler::getInstance();

    if (!inputHandler->isJoysticksInitialised()) {
        return;
    }

    if (inputHandler->getButtonState(0, 3)) {
        velocity.setX(1);
    }

    if (inputHandler->xValue(0, 1) > 0 || inputHandler->xValue(0, 1) < 0) {
        velocity.setX(1 * inputHandler->xValue(0, 1));
    }

    if (inputHandler->yValue(0, 1) > 0 || inputHandler->yValue(0, 1) < 0) {
        velocity.setY(1 * inputHandler->yValue(0, 1));
    }

    if (inputHandler->xValue(0, 2) > 0 || inputHandler->xValue(0, 2) < 0) {
        velocity.setX(1 * inputHandler->xValue(0, 2));
    }

    if (inputHandler->yValue(0, 2) > 0 || inputHandler->yValue(0, 2) < 0) {
        velocity.setY(1 * inputHandler->yValue(0, 2));
    }
}
