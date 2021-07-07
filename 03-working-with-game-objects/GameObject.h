//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_GAMEOBJECT_H
#define SDLBOOK_CMAKE_GAMEOBJECT_H

#include<iostream>
#include<SDL.h>
#include "LoaderParams.h"

class GameObject {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* params) {}
    virtual ~GameObject() {}

    int x;
    int y;
    int width;
    int height;

    int currentFrame;
    int currentRow;

    std::string textureID;
};


#endif //SDLBOOK_CMAKE_GAMEOBJECT_H
