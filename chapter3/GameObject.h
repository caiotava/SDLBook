#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include<iostream>
#include"LoaderParams.h"

class GameObject
{
   public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

    protected:
        GameObject(const LoaderParams *pParams) {};
        virtual ~GameObject() {};
};

#endif
