#include<iostream>
#include"PlayState.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
}

void PlayState::render()
{
}

bool PlayState::onEnter()
{
    std::cout << "entering PlayState" << std::endl;
    return true;
}

bool PlayState::onExit()
{
    std::cout << "exiting PLayState" << std::endl;
    return true;
}
