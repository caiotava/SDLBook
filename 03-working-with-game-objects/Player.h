//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_PLAYER_H
#define SDLBOOK_CMAKE_PLAYER_H

#include "SDLGameObject.h"

class Player : public SDLGameObject {
public:
    Player(LoaderParams* params) : SDLGameObject(params) {}

    virtual void update();
    virtual void clean() {
        std::cout << "clean player" << std::endl;
    }
};


#endif //SDLBOOK_CMAKE_PLAYER_H
