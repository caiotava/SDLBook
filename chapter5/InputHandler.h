#ifndef __INPUTHANDLE_H__
#define __INPUTHANDLE_H__

#include<vector>
#include<SDL2/SDL.h>
#include"Vector2D.h"

enum MouseButtons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

const int joystickDeadZone = 10000;

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

        bool getButtonState(int joystickId, int buttonNumber);
        bool getMouseButtonState(int buttonNumber);

        Vector2D* getMousePosition();

        bool isKeyDown(SDL_Scancode key);

    private:
        InputHandler();
        ~InputHandler() {}

        void onKeyDown();
        void onKeyUp();

        void onMouseMove(SDL_Event &event);
        void onMouseButtonDown(SDL_Event &event);
        void onMouseButtonUp(SDL_Event &event);

        void onJoystickAxisMove(SDL_Event &event);
        void onJoystickButtonDown(SDL_Event &event);
        void onJoystickButtonUp(SDL_Event &event);

        static InputHandler *instance;

        std::vector<SDL_Joystick*> joysticks;
        std::vector< std::pair<Vector2D*, Vector2D*> > joysticksValues;
        std::vector< std::vector<bool> > buttonStates;
        std::vector<bool> mouseButtonStates;
        Vector2D *mousePosition;
        bool joysticksInitialised;

        Uint8 *keyStates;
};

typedef InputHandler TheInputHandler;

#endif
