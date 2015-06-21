#include<SDL2/SDL.h>
#include"Enemy.h"

Enemy::Enemy(const LoaderParams *pParams): SDLGameObject(pParams)
{
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    y += 1;
    x += 1;
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}
