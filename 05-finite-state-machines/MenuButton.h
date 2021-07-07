//
// Created by caiotava on 4/21/21.
//

#ifndef SDLBOOK_CMAKE_MENUBUTTON_H
#define SDLBOOK_CMAKE_MENUBUTTON_H

#include "SDLGameObject.h"

enum {
    MOUSE_OUT = 0,
    MOUSE_OVER = 1,
    MOUSER_CLICKED = 2
};

class MenuButton : public SDLGameObject {
public:
    MenuButton(const LoaderParams* params, void (*callback)());

    virtual void update();
    virtual void draw();
private:

    bool released;
    void (*callback)();
};


#endif //SDLBOOK_CMAKE_MENUBUTTON_H
