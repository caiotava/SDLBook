#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<iostream>
#include"GameObject.h"

class Player: public GameObject
{
    public:
        void update();
        void clean()
        {
            std::cout << "clean PLayer";
        }
};

#endif
