//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_ENEMY_H
#define SDLBOOK_CMAKE_ENEMY_H

#include "GameObjectFactory.h"
#include "ShooterObject.h"

class Enemy : public SDLGameObject {
public:
    virtual std::string type() { return "Enemy"; }
protected:
    int health;

    Enemy() : SDLGameObject() {}
    virtual ~Enemy() {}
};

#endif //SDLBOOK_CMAKE_ENEMY_H
