#include<SDL2/SDL.h>
#include"Enemy.h"

Enemy::Enemy(const LoaderParams *pParams): SDLGameObject(pParams)
{
    velocity.setY(2);
    velocity.setX(0.001);
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    position.setY(position.getX() + 1);
    position.setX(position.getY() + 1);
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}
