#ifndef __MENUBUTTON_H__
#define __MENUBUTTON_H__

#include"SDLGameObject.h"

class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams *pParams);

        virtual void draw();
        virtual void update();
        virtual void clean();

    private:
        enum buttonState {
            MOUSE_OUT = 1,
            MOUSE_OVER = 2,
            CLICKED = 2
        };
};

#endif
