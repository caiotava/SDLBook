//
// Created by caiotava on 4/23/21.
//

#ifndef SDLBOOK_CMAKE_GAMEOVERSTATE_H
#define SDLBOOK_CMAKE_GAMEOVERSTATE_H

#include "GameObject.h"
#include "MenuState.h"
#include<vector>

class GameOverState : public MenuState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return gameOverID; }

private:
    static void gameOverToMain();
    static void restartPlay();

    static const std::string gameOverID;

    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    std::vector<GameObject*> objects;
};


#endif //SDLBOOK_CMAKE_GAMEOVERSTATE_H
