#include"GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState)
{
    gameStates.push_back(pState);
    gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if (gameStates.empty()) {
        return;
    }

    if (gameStates.back()->onExit()) {
        delete gameStates.back();
        gameStates.pop_back();
    }
}

void GameStateMachine::changeState(GameState *pState)
{
    if (!gameStates.empty()) {
        if (gameStates.back()->getStateId() == pState->getStateId()) {
            return;
        }

        if (gameStates.back()->onExit()) {
            delete gameStates.back();
            gameStates.pop_back();
        }
    }

    gameStates.push_back(pState);
    gameStates.back()->onEnter();
}
