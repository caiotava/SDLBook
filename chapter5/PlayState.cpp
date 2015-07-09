#include<iostream>
#include"Game.h"
#include"PlayState.h"
#include"Player.h"
#include"LoaderParams.h"
#include"TextureManager.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void PlayState::render()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}

bool PlayState::onEnter()
{
    if (!TheTextureManager::getInstance()->load("assets/helicopter.png", "helicopter", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));

    gameObjects.push_back(player);

    std::cout << "Entering PlayState." <<  std::endl;

    return true;
}

bool PlayState::onExit()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->clean();
    }

    gameObjects.clear();
    TheTextureManager::getInstance()->clearFromTextureMap("helicopter");

    return true;
}
