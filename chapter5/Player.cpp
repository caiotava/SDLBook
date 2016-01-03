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

    velocity = (*mousePosition - position) / 50;
}
