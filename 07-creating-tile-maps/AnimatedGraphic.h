//
// Created by caiotava on 4/23/21.
//

#ifndef SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H
#define SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H

#include "GameObjectFactory.h"
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject {
public:
    virtual void update();
    virtual void load(const LoaderParams* params);
private:
    int animatedSpeed;
};

class AnimatedGraphicCreator : public BaseCreator {
public:
    GameObject* createGameObject() const {
        return new AnimatedGraphic();
    }
};

#endif //SDLBOOK_CMAKE_ANIMATEDGRAPHIC_H
