//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_SDLGAMEOBJECT_H
#define SDLBOOK_CMAKE_SDLGAMEOBJECT_H

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
    SDLGameObject(const LoaderParams* params);

    virtual void draw();
    virtual void update();
    virtual void clean() {};

    Vector2D& getPosition();
    int getWidth();
    int getHeight();
protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;

    int width;
    int height;

    int currentRow;
    int currentFrame;
    int numberFrames;
};


#endif //SDLBOOK_CMAKE_SDLGAMEOBJECT_H
