#include"PlayState.h"
#include"MenuState.h"
#include"Game.h"
#include"MenuButton.h"
#include"TextureManager.h"

const std::string MenuState::menuId = "MENU";

void MenuState::update()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void MenuState::render()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}

bool MenuState::onEnter()
{
    std::cout << "entering MenuState" << std::endl;

    if (!TheTextureManager::getInstance()->load("assets/button.png", "playbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::getInstance()->load("assets/exit.png", "exitbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    GameObject *buttonPlay = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), menuToPlay);
    GameObject *buttonExit = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), exitFromMenu);

    gameObjects.push_back(buttonPlay);
    gameObjects.push_back(buttonExit);

    return true;
}

bool MenuState::onExit()
{
    std::cout << "exiting MenuState" << std::endl;

    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->clean();
    }

    gameObjects.clear();
    TheTextureManager::getInstance()->clearFromTextureMap("playbutton");
    TheTextureManager::getInstance()->clearFromTextureMap("exitbutton");

    return true;
}

void MenuState::menuToPlay()
{
    std::cout << "Play button clicked" << std::endl;
}

void MenuState::exitFromMenu()
{
    std::cout << "Exit button clicked" << std::endl;
}
