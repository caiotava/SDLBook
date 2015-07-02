#include "MenuState.h"

const std::string MenuState::menuId = "MENU";

void MenuState::update()
{
}

void MenuState::render()
{
}

bool MenuState::onEnter()
{
    std::cout << "entering MenuState" << std::endl;
    return true;
}

bool MenuState::onExit()
{
    std::cout << "exiting MenuState" << std::endl;
    return true;
}
