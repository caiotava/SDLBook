//
// Created by caiotava on 4/28/21.
//

#ifndef SDLBOOK_CMAKE_BULLET_H
#define SDLBOOK_CMAKE_BULLET_H

#include "ShooterObject.h"

class PlayerBullet : public SDLGameObject {
public:
    PlayerBullet() : SDLGameObject() {}

    virtual ~PlayerBullet();

    virtual std::string type() {
        return "PlayerBullet";
    }

    virtual void load(std::unique_ptr<LoaderParams> params, Vector2D heading) {
        SDLGameObject::load(std::move(params));

        this->heading = heading;
    }

    virtual void collision() {
        dead = true;
    }

    virtual void update() {
        velocity.setX(heading.getX());
        velocity.setY(heading.getY());

        SDLGameObject::update();
    }

private:
    Vector2D heading;
};

class EnemyBullet : public PlayerBullet {
public:
    EnemyBullet() : PlayerBullet() {}

    virtual ~EnemyBullet() {}

    virtual std::string type() { return "EnemyBullet"; }
};

#endif //SDLBOOK_CMAKE_BULLET_H
