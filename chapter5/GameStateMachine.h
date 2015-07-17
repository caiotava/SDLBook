#ifndef __GAMESTATEMACHINE_H__
#define __GAMESTATEMACHINE_H__

#include<vector>
#include"GameState.h"

class GameStateMachine
{
    public:
        void update();
        void render();
        void pushState(GameState *pState);
        void changeState(GameState *pState);
        void popState();

    private:
        std::vector<GameState*> gameStates;
};

#endif
