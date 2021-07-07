//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_SDLGAMEOBJECT_H
#define SDLBOOK_CMAKE_SDLGAMEOBJECT_H

#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* params);

    virtual void draw();
    virtual void update() {};
    virtual void clean() {};
protected:
    int x;
    int y;

    int width;
    int height;

    int currentRow;
    int currentFrame;
};


#endif //SDLBOOK_CMAKE_SDLGAMEOBJECT_H
