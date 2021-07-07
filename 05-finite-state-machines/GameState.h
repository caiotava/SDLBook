//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_GAMESTATE_H
#define SDLBOOK_CMAKE_GAMESTATE_H

#include<string>

class GameState {
public:
    virtual void update() = 0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual std::string getStateID() const = 0;
};


#endif //SDLBOOK_CMAKE_GAMESTATE_H
