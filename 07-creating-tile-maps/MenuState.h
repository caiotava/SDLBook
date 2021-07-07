//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_MENUSTATE_H
#define SDLBOOK_CMAKE_MENUSTATE_H

#include "GameObject.h"
#include "GameState.h"
#include<vector>

class MenuState : public GameState {
protected:
    typedef void(*Callback)();
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

    std::vector<Callback> callbacks;
};

#endif //SDLBOOK_CMAKE_MENUSTATE_H
