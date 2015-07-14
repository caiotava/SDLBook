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
    currentFrame = int((SDL_GetTicks() / 100) % 5);

    if (position.getY() < 0) {
        velocity.setY(2);
    }
    else if (position.getY() > 400) {
        velocity.setY(-2);
    }

    SDLGameObject::update();
}
