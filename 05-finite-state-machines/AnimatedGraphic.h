//
// Created by caiotava on 4/23/21.
//

#ifndef SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H
#define SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject {
public:
    AnimatedGraphic(const LoaderParams* params, int animationSpeed);
    virtual void update();
private:
    int animatedSpeed;
};


#endif //SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H
