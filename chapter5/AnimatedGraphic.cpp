#include<SDL2/SDL.h>
#include"AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *pParams, int pAnimateSpeed):
    SDLGameObject(pParams), animateSpeed(pAnimateSpeed)
{
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
    currentFrame = int(SDL_GetTicks() / (1000 / animateSpeed) % 2);
}
