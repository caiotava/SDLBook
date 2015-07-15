#ifndef __PLAYSTATE_H__
#define __PLAYSTATE_H__

#include<vector>
#include"GameState.h"
#include"GameObject.h"
#include"SDLGameObject.h"

class PlayState : public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        bool checkCollision(SDLGameObject* source, SDLGameObject* destination);

        virtual std::string getStateId() const { return playId; }

    private:
        static const std::string playId;

        std::vector<GameObject*> gameObjects;
};

#endif
