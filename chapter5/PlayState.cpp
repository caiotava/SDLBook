#include<iostream>
#include"PlayState.h"
#include"Game.h"
#include"TextureManager.h"
#include"Player.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
	for (int x = 0; x < gameObjects.size(); x++) {
		gameObjects[x]->update();
	}
}

void PlayState::render()
{
	for (int x = 0; x < gameObjects.size(); x++) {
		gameObjects[x]->draw();
	}
}

bool PlayState::onEnter()
{
    std::cout << "entering PlayState" << std::endl;

	if (!TheTextureManager::getInstance()->load("assets/helicopter.png", "helicopter", TheGame::getInstance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));

	gameObjects.push_back(player);

	return true;
}

bool PlayState::onExit()
{
    std::cout << "exiting PLayState" << std::endl;

	for (int x = 0; x < gameObjects.size(); x++) {
		gameObjects[x]->clean();
	}

	gameObjects.clear();
	TheTextureManager::getInstance()->clearFromTextureMap("helicopter");

	return true;
}
