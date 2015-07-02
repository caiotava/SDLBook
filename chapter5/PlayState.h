#ifndef __PLAYSTATE_H__
#define __PLAYSTATE_H__

#include"GameState.h"

class PlayState : public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateId() const { return playId; }

    private:
        static const std::string playId;
};

#endif
