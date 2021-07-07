//
// Created by caiotava on 4/18/21.
//

#include "Game.h"
#include "InputHandler.h"
#include<iostream>

InputHandler *InputHandler::instance = 0;

InputHandler *InputHandler::Instance() {
    if (instance == 0) {
        instance = new InputHandler();
    }

    return instance;
}

InputHandler::InputHandler() : mousePosition(new Vector2D(0, 0)) {

}

void InputHandler::initialiseJoysticks() {
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    for (int i = 0; i < 3; i++) {
        mouseButtonStates.push_back(false);
    }

    if (SDL_NumJoysticks() <= 0) {
        joysticksInitialised = false;
        return;
    }

    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        SDL_Joystick *joy = SDL_JoystickOpen(i);

        if (!joy) {
            std::cout << SDL_GetError() << std::endl;
            continue;
        }

        joysticks.push_back(joy);
        joystickValues.push_back(
                std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0))
        );


        std::vector<bool> tmpButtons;
        for (int j = 0; j < SDL_JoystickNumButtons(joy); j++) {
            tmpButtons.push_back(false);
        }

        buttonStates.push_back(tmpButtons);
    }

    SDL_JoystickEventState(SDL_ENABLE);

    joysticksInitialised = true;

    std::cout << "initialised " << joysticks.size() << " joystick(s)" << std::endl;
}

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                Game::Instance()->quit();
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                keystates = (Uint8 *) SDL_GetKeyboardState(0);
                break;

            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            case SDL_JOYAXISMOTION:
                onJoystickAxisMove(event);
                break;

            case SDL_JOYBUTTONDOWN:
                onJoystickButtonDown(event);
                break;

            case SDL_JOYBUTTONUP:
                onJoystickButtonUp(event);
                break;
        }
    }
}

void InputHandler::onMouseButtonDown(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates[LEFT] = true;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates[MIDDLE] = true;
    }

    if (event.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates[LEFT] = false;
    }

    if (event.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates[MIDDLE] = false;
    }

    if (event.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::onMouseMove(SDL_Event &event) {
    mousePosition->setX(event.motion.x);
    mousePosition->setY(event.motion.y);
}

void InputHandler::onJoystickAxisMove(SDL_Event &event) {
    int whichOne = event.jaxis.which;

    if (event.jaxis.axis == 0) {
        if (event.jaxis.value > joystickDeadZone) {
            joystickValues[whichOne].first->setX(1);
        } else if (event.jaxis.value < -joystickDeadZone) {
            joystickValues[whichOne].first->setX(-1);
        } else {
            joystickValues[whichOne].first->setX(0);
        }
    }

    if (event.jaxis.axis == 1) {
        if (event.jaxis.value > joystickDeadZone) {
            joystickValues[whichOne].first->setY(1);
        } else if (event.jaxis.value < -joystickDeadZone) {
            joystickValues[whichOne].first->setY(-1);
        } else {
            joystickValues[whichOne].first->setY(0);
        }
    }

    if (event.jaxis.axis == 3) {
        if (event.jaxis.value > joystickDeadZone) {
            joystickValues[whichOne].second->setX(1);
        } else if (event.jaxis.value < -joystickDeadZone) {
            joystickValues[whichOne].second->setX(-1);
        } else {
            joystickValues[whichOne].second->setX(0);
        }
    }

    if (event.jaxis.axis == 4) {
        if (event.jaxis.value > joystickDeadZone) {
            joystickValues[whichOne].second->setY(1);
        } else if (event.jaxis.value < -joystickDeadZone) {
            joystickValues[whichOne].second->setY(-1);
        } else {
            joystickValues[whichOne].second->setY(0);
        }
    }
}

void InputHandler::onJoystickButtonDown(SDL_Event &event) {
    int whichOne = event.jaxis.which;

    buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event &event) {
    int whichOne = event.jaxis.which;

    buttonStates[whichOne][event.jbutton.button] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    return keystates != 0 && keystates[key] == 1;
}

bool InputHandler::getButtonState(int joy, int buttonNumber) {
    return buttonStates[joy][buttonNumber];
}

void InputHandler::clean() {
    if (!joysticksInitialised) {
        return;
    }

    for (auto &x : joysticks) {
        SDL_JoystickClose(x);
    }

    joysticks.clear();
}

int InputHandler::xvalue(int joy, int stick) {
    if (joysticks.size() > 0) {
        if (stick == 1) {
            return joystickValues[joy].first->getX();
        } else if (stick == 2) {
            return joystickValues[joy].second->getX();
        }
    }

    return 0;
}

int InputHandler::yvalue(int joy, int stick) {
    if (joysticks.size() > 0) {
        if (stick == 1) {
            return joystickValues[joy].first->getY();
        } else if (stick == 2) {
            return joystickValues[joy].second->getY();
        }
    }

    return 0;
}
