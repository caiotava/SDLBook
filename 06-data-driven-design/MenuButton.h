//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_MENUBUTTON_H
#define SDLBOOK_CMAKE_MENUBUTTON_H

#include "GameObjectFactory.h"
#include "SDLGameObject.h"

enum {
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    MOUSER_CLICKED = 2
};

class MenuButton : public SDLGameObject {
public:
    MenuButton();

    virtual void update();
    virtual void draw();
    virtual void load(const LoaderParams* params);

    void setCallback(void(*callback)()) { this->callback = callback; }
    int getCallbackID() { return callbackID; }
private:

    bool released;
    int callbackID;
    void (*callback)();
};

class MenuButtonCreator : public BaseCreator {
    GameObject* createGameObject() const {
        return new MenuButton();
    }
};

#endif //SDLBOOK_CMAKE_MENUBUTTON_H
