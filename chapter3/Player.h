#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<iostream>
#include"GameObject.h"

class PLayer: public GameObject
{
    public:
        void draw()
        {
            GameObject::draw();
            std::cout << "draw player";
        }

        void update()
        {
            std::cout << "update player";

            x = 10;
            y = 20;
        }

        void clean()
        {
            GameObject::clean();
            std::cout << "clean PLayer";
        }
};

#endif
