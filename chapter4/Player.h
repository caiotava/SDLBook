#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<iostream>
#include"SDLGameObject.h"
#include"LoaderParams.h"

class Player: public SDLGameObject
{
    public:
        Player (const LoaderParams *pParams);

        virtual void draw();
        virtual void update();
        virtual void clean() {}

    private:
        void handleInput();
};

#endif
