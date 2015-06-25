#ifndef __SDLGAMEOBJECT_H__
#define __SDLGAMEOBJECT_H__

#include<iostream>
#include"GameObject.h"
#include"LoaderParams.h"
#include"Vector2D.h"

class SDLGameObject: public GameObject
{
    public:
        SDLGameObject(const LoaderParams *pParams);

        virtual void draw();
        virtual void update();
        virtual void clean() {}

    protected:
        int width;
        int height;

        int currentRow;
        int currentFrame;

        std::string textureId;

        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
};

#endif
