#include<iostream>
#include"InputHandler.h"
#include"Game.h"

InputHandler *InputHandler::instance = 0;

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
    }
}

int InputHandler::xValue(int joystickId, int stickId)
{
    if (joysticksValues.size() <= 0) {
        return 0;
    }

    if (stickId == 1) {
        return joysticksValues[joystickId].first->getY();
    }
}
