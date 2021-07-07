//
// Created by caiotava on 4/18/21.
//

#ifndef SDLBOOK_CMAKE_INPUTHANDLER_H
#define SDLBOOK_CMAKE_INPUTHANDLER_H

#include "SDL.h"
#include "Vector2D.h"
#include<vector>

const int joystickDeadZone = 10000;

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {
public:
    static InputHandler* Instance();
    void update();
    void clean();

    bool getMouseButtonState(int buttonNumber) { return mouseButtonStates[buttonNumber]; }
    Vector2D* getMousePosition() { return mousePosition; }

    void initialiseJoysticks();
    bool isJoysticksInitialised() {
        return joysticksInitialised;
    }

    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

    bool isKeyDown(SDL_Scancode key);
    bool getButtonState(int joy, int buttonNumber);

private:
    InputHandler();
    ~InputHandler() {}

    static InputHandler* instance;

    Uint8* keystates;

    std::vector<bool> mouseButtonStates;
    Vector2D* mousePosition;

    std::vector<SDL_Joystick*> joysticks;
    std::vector<std::vector<bool>> buttonStates;
    std::vector<std::pair<Vector2D*, Vector2D*>> joystickValues;

    bool joysticksInitialised;

    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);
};


#endif //SDLBOOK_CMAKE_INPUTHANDLER_H
