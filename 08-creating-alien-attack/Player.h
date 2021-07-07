//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_PLAYER_H
#define SDLBOOK_CMAKE_PLAYER_H

#include "GameObjectFactory.h"
#include "ShooterObject.h"

class Player : public SDLGameObject {
public:
    virtual void update();

    virtual void clean() {
        std::cout << "clean player" << std::endl;
    }

private:
    void handleInput();

    void resurrect();

    void handleAnimation();

    int invulnerable;
    int invulnerableTime;
    int invulnerableCounter;
};

class PlayerCreator : public BaseCreator {
    GameObject *createGameObject() const {
        return new Player();
    }
};

#endif //SDLBOOK_CMAKE_PLAYER_H
