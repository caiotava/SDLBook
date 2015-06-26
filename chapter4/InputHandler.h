#ifndef __INPUTHANDLE_H__
#define __INPUTHANDLE_H__

#include<vector>
#include<SDL2/SDL.h>
#include"Vector2D.h"

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

        int xValue(int joystickId, int stickId);
        int yValue(int joystickId, int stickId);

        const int joystickDeadZone = 10000;

    private:
        InputHandler() {}
        ~InputHandler() {}

        static InputHandler *instance;

        std::vector<SDL_Joystick*> joysticks;
        std::vector< std::pair<Vector2D*, Vector2D*> > joysticksValues;
        bool joysticksInitialised;
};

typedef InputHandler TheInputHandler;

#endif
