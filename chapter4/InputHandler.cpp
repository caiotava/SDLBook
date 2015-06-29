#include<iostream>
#include"InputHandler.h"
#include"Game.h"

InputHandler *InputHandler::instance = 0;

InputHandler::InputHandler()
{
    for (int x = 0; x < 3; x++) {
        mouseButtonStates.push_back(false);
    }
}

void InputHandler::initialiseJoysticks()
{
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    if (SDL_NumJoysticks() <= 0) {
        joysticksInitialised = false;
        return;
    }

    for (int x = 0; x < SDL_NumJoysticks(); x++) {
        SDL_Joystick *joystick = SDL_JoystickOpen(x);

        if (!joystick) {
            std::cout << SDL_GetError() << std::endl;
            continue;
        }

        joysticks.push_back(joystick);
        joysticksValues.push_back(
            std::make_pair(
                new Vector2D(0, 0),
                new Vector2D(0, 0)
            )
        );

        std::vector<bool> buttonValues;

        for (int i = 0; i < SDL_JoystickNumButtons(joystick); i++) {
            buttonValues.push_back(false);
        }

        buttonStates.push_back(buttonValues);
    }

    SDL_JoystickEventState(SDL_ENABLE);
    joysticksInitialised = true;

    std::cout << "Initialised " << joysticks.size() << " joystick(s)." << std::endl;
}

void InputHandler::clean()
{
    if (!joysticksInitialised) {
        return;
    }

    for (int x = 0; x < SDL_NumJoysticks(); x++) {
        SDL_JoystickClose(joysticks[x]);
    }
}

void InputHandler::update()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            TheGame::getInstance()->clean();
        }

        if (event.type == SDL_MOUSEBUTTONDOWN) {
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

        if (event.type == SDL_MOUSEBUTTONUP) {
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

        if (event.type == SDL_JOYBUTTONDOWN) {
            int whichOne = event.jaxis.which;

            buttonStates[whichOne][event.jbutton.button] = true;
        }

        if (event.type == SDL_JOYBUTTONUP) {
            int whichOne = event.jaxis.which;

            buttonStates[whichOne][event.jbutton.button] = false;
        }

        if (event.type == SDL_JOYAXISMOTION) {
            int whichOne = event.jaxis.which;

            if (event.jaxis.axis == 0) {
                joysticksValues[whichOne].first->setX(0);

                if (event.jaxis.value > joystickDeadZone) {
                    joysticksValues[whichOne].first->setX(1);
                }
                else if (event.jaxis.value < -joystickDeadZone) {
                    joysticksValues[whichOne].first->setX(-1);
                }
            }

            if (event.jaxis.axis == 1) {
                joysticksValues[whichOne].first->setY(0);

                if (event.jaxis.value > joystickDeadZone) {
                    joysticksValues[whichOne].first->setY(1);
                }
                else if (event.jaxis.value < -joystickDeadZone) {
                    joysticksValues[whichOne].first->setY(-1);
                }
            }

            if (event.jaxis.axis == 3) {
                joysticksValues[whichOne].second->setX(0);

                if (event.jaxis.value > joystickDeadZone) {
                    joysticksValues[whichOne].second->setX(1);
                }
                else if (event.jaxis.value < -joystickDeadZone) {
                    joysticksValues[whichOne].second->setX(-1);
                }
            }

            if (event.jaxis.axis == 4) {
                joysticksValues[whichOne].second->setY(0);

                if (event.jaxis.value > joystickDeadZone) {
                    joysticksValues[whichOne].second->setY(1);
                }
                else if (event.jaxis.value < -joystickDeadZone) {
                    joysticksValues[whichOne].second->setY(-1);
                }
            }
        }
    }
}

int InputHandler::xValue(int joystickId, int stickId)
{
    if (joysticksValues.size() <= 0) {
        return 0;
    }

    if (stickId == 1) {
        return joysticksValues[joystickId].first->getX();
    }
    else if (stickId == 2) {
        return joysticksValues[joystickId].second->getX();
    }

    return 0;
}

int InputHandler::yValue(int joystickId, int stickId)
{
    if (joysticksValues.size () <= 0) {
        return 0;
    }

    if (stickId == 1) {
        return joysticksValues[joystickId].first->getY();
    }
    else if (stickId == 2) {
        return joysticksValues[joystickId].second->getY();
    }

    return 0;
}

bool InputHandler::getButtonState(int joystickId, int buttonNumber)
{
    return buttonStates[joystickId][buttonNumber];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return mouseButtonStates[buttonNumber];
}
