#ifndef __GAMEOVERSTATE_H__
#define __GAMEOVERSTATE_H__

#include<vector>
#include"GameState.h"
#include"GameObject.h"

class GameOverState : public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateId() const { return gameOverId; }

    private:
        static void gameOverToMain();
        static void restartPlay();

        static const std::string gameOverId;

        std::vector<GameObject*> gameObjects;
};

#endif
