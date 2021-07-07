//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_PLAYSTATE_H
#define SDLBOOK_CMAKE_PLAYSTATE_H

#include "ShooterObject.h"
#include "GameState.h"
#include "Level.h"
#include<string>
#include<vector>

class PlayState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return playID; }

    bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

private:
    std::vector<GameObject*> objects;

    static const std::string playID;

    Level* level;
};


#endif //SDLBOOK_CMAKE_PLAYSTATE_H
