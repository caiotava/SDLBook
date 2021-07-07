//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_PAUSESTATE_H
#define SDLBOOK_CMAKE_PAUSESTATE_H

#include "GameObject.h"
#include "MenuState.h"
#include<vector>

class PauseState : public MenuState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return pauseID; }

private:
    static void pauseToMain();
    static void resumePlay();

    static const std::string pauseID;

    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    std::vector<GameObject*> objects;
};


#endif //SDLBOOK_CMAKE_PAUSESTATE_H
