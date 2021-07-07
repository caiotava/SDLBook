//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_PAUSESTATE_H
#define SDLBOOK_CMAKE_PAUSESTATE_H

#include "GameObject.h"
#include "GameState.h"
#include<vector>

class PauseState : public GameState {
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

    std::vector<GameObject*> objects;
};


#endif //SDLBOOK_CMAKE_PAUSESTATE_H
