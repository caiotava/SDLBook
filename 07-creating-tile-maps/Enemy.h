//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_ENEMY_H
#define SDLBOOK_CMAKE_ENEMY_H

#include "GameObjectFactory.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
public:
    virtual void update();
    virtual void load(const LoaderParams* params);
};

class EnemyCreator : public BaseCreator {
public:
    GameObject* createGameObject() const {
        return new Enemy();
    }
};

#endif //SDLBOOK_CMAKE_ENEMY_H
