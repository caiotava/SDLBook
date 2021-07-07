//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_GAMESTATEMACHINE_H
#define SDLBOOK_CMAKE_GAMESTATEMACHINE_H

#include "GameState.h"
#include<vector>

class GameStateMachine {
public:
    void update();
    void render();

    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();

private:
    std::vector<GameState*> gameStates;
};


#endif //SDLBOOK_CMAKE_GAMESTATEMACHINE_H
