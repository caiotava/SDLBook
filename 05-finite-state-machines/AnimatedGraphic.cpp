//
// Created by caiotava on 4/23/21.
//

#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *params, int animationSpeed):
    SDLGameObject(params),
    animatedSpeed(animationSpeed) {
}

void AnimatedGraphic::update() {
    currentFrame = int(SDL_GetTicks() / (1000 / animatedSpeed) % numberFrames);
}