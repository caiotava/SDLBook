#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<iostream>
#include"GameObject.h"

class PLayer: public GameObject
{
    public:
        void update();
        void clean()
        {
            GameObject::clean();
            std::cout << "clean PLayer";
        }
};

#endif
