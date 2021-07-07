//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_GAMEOBJECT_H
#define SDLBOOK_CMAKE_GAMEOBJECT_H

#include "LoaderParams.h"
#include "Vector2D.h"
#include<SDL.h>
#include<iostream>
#include<memory>

class GameObject {
public:
    virtual ~GameObject() {}

    virtual void draw() = 0;

    virtual void update() = 0;

    virtual void clean() = 0;

    virtual void collision() = 0;

    virtual std::string type() = 0;

    Vector2D &getPosition() { return position; }

    int getWidth() { return width; }

    int getHeight() { return height; }

    void scroll(float scrollSpeed) { position.setX(position.getX() - scrollSpeed); }

    bool isUpdating() { return updating; }

    bool isDead() { return dead; }

    bool isDying() { return dying; }

    void setUpdating(bool u) { updating = u; }

    virtual void load(std::unique_ptr<LoaderParams> const &params) = 0;

protected:
    GameObject() : position(0, 0),
     velocity(0,0),
     acceleration(0,0),
     width(0),
     height(0),
     currentRow(0),
     currentFrame(0),
     numFrames(0),
     updating(false),
     dead(false),
     dying(false),
     angle(0),
     alpha(0)
     {}

    int width;
    int height;
    bool updating;
    bool dead;
    bool dying;
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;

    double angle;

    int alpha;

    int currentFrame;
    int currentRow;
    int numFrames;

    std::string textureID;
};


#endif //SDLBOOK_CMAKE_GAMEOBJECT_H
