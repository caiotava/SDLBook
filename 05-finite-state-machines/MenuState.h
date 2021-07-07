//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_MENUSTATE_H
#define SDLBOOK_CMAKE_MENUSTATE_H

#include "GameObject.h"
#include "GameState.h"
#include<vector>

class MenuState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return menuID; }

private:
    std::vector<GameObject*> objects;

    static void menuToPlay();
    static void exitFromMenu();

    static const std::string menuID;
};

#endif //SDLBOOK_CMAKE_MENUSTATE_H
