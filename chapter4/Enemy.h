#ifndef __ENEMY_H__
#define __ENEMY_H__

#include<iostream>
#include"SDLGameObject.h"
#include"LoaderParams.h"

class Enemy: public SDLGameObject
{
    public:
        Enemy(const LoaderParams *pParams);

        virtual void draw();
        virtual void update();
        virtual void clean() {}
};

#endif
