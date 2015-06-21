#ifndef __ENEMY_H__
#define __ENEMY_H__

#include<iostream>
#include"GameObject.h"

class Enemy: public GameObject
{
    public:
        void update();
        void clean()
        {
            std::cout << "Enemy clean.";
        }
};

#endif
