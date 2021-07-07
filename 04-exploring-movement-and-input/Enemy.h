//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_ENEMY_H
#define SDLBOOK_CMAKE_ENEMY_H

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    Enemy(LoaderParams* params) : SDLGameObject(params) {}

    virtual void update();
};


#endif //SDLBOOK_CMAKE_ENEMY_H
