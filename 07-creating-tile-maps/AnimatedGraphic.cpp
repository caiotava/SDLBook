//
// Created by caiotava on 4/23/21.
//

#include "AnimatedGraphic.h"

void AnimatedGraphic::load(const LoaderParams *params) {
    SDLGameObject::load(params);

    animatedSpeed = params->getAnimateSpeed();
}

void AnimatedGraphic::update() {
    currentFrame = int(SDL_GetTicks() / (1000 / animatedSpeed) % numberFrames);
}