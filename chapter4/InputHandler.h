#ifndef __INPUTHANDLE_H__
#define __INPUTHANDLE_H__

#include<vector>
#include<SDL2/SDL.h>

class InputHandler
{
    public:
        static InputHandler* getInstance()
        {
            if (!instance) {
                instance = new InputHandler();
            }

            return instance;
        }

        void update();
        void clean();
        void initialiseJoysticks();
        bool isJoysticksInitialised()
        {
            return joysticksInitialised;
        }

    private:
        InputHandler() {}
        ~InputHandler() {}

        static InputHandler *instance;

        std::vector<SDL_Joystick*> joysticks;
        bool joysticksInitialised;
};

typedef InputHandler TheInputHandler;

#endif
