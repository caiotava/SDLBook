//
// Created by caiotava on 4/24/21.
//

#ifndef SDLBOOK_CMAKE_MAINMENUSTATE_H
#define SDLBOOK_CMAKE_MAINMENUSTATE_H

#include "GameObject.h"
#include "MenuState.h"
#include<vector>

class MainMenuState : public MenuState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return menuID; }

private:
    std::vector<GameObject*> objects;

    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    static void menuToPlay();
    static void exitFromMenu();

    static const std::string menuID;
};


#endif //SDLBOOK_CMAKE_MAINMENUSTATE_H
