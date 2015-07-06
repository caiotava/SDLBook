#ifndef __MENUBUTTON_H__
#define __MENUBUTTON_H__

#include"SDLGameObject.h"

class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams *pParams, void (*callback)());

        virtual void draw();
        virtual void update();
        virtual void clean() {}

    private:
        enum buttonState {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };

        void (*onClickEvent) ();

        bool released;
};

#endif
