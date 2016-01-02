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

    currentFrame = int((SDL_GetTicks() / 100) % 5);

    SDLGameObject::update();
}

void Player::handleInput()
{
    InputHandler *inputHandler = TheInputHandler::getInstance();

    Vector2D *mousePosition = inputHandler->getMousePosition();

    velocity = (*mousePosition - position) / 100;

    if (inputHandler->getMouseButtonState(LEFT)) {
        velocity.setX(1);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_RIGHT)) {
        velocity.setX(2);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_LEFT)) {
        velocity.setX(-2);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_UP)) {
        velocity.setY(-2);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_DOWN)) {
        velocity.setY(2);
    }

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
