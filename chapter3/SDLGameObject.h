#ifndef __SDLGAMEOBJECT_H__
#define __SDLGAMEOBJECT_H__

#include<iostream>
#include"GameObject.h"
#include"LoaderParams.h"

class SDLGameObject: public GameObject
{
    public:
        SDLGameObject(const LoaderParams *pParams);

        virtual void draw();
        virtual void update() {}
        virtual void clean() {}

    protected:
        int x;
        int y;

        int width;
        int height;

        int currentRow;
        int currentFrame;

        std::string textureId;
};

#endif
