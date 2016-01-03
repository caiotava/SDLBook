#include"AnimatedGraphic.h"
#include<SDL2/SDL.h>

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int pAnimateSpeed) :
    SDLGameObject(pParams),
    animateSpeed(pAnimateSpeed)
{
}

void AnimatedGraphic::update()
{
    currentFrame = int((SDL_GetTicks() / 100) % 2);
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}
