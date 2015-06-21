#include<SDL2/SDL.h>
#include"Player.h"

Player::Player(const LoaderParams *pParams): SDLGameObject(pParams)
{
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    x--;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}
