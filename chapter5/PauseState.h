#ifndef __PAUSESTATE_H__
#define __PAUSESTATE_H__

#include<vector>
#include"GameState.h"
#include"GameObject.h"

class PauseState: public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateId() const { return pauseId; }

    private:
        static const std::string pauseId;

        std::vector<GameObject*> gameObjects;

        static void pauseToMain();
        static void resumePlay();
};

#endif
