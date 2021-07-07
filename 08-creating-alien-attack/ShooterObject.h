//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_SHOOTEROBJECT_H
#define SDLBOOK_CMAKE_SHOOTEROBJECT_H

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
    ~SDLGameObject() {};

    virtual void draw();

    virtual void update();

    virtual void clean() {};

    virtual void collision() {};

    virtual void load(std::unique_ptr<LoaderParams> const &params);

    virtual std::string type() { return "SDLGameObject"; };

protected:
    SDLGameObject();

    void doDyingAnimation();

    int bulletFiringSpeed;
    int bulletCounter;

    int moveSpeed;

    int dyingTime;
    int dyingCounter;

    bool playedDeathSound;
};


#endif //SDLBOOK_CMAKE_SHOOTEROBJECT_H
