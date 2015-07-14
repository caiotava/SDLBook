#include<iostream>
#include"PlayState.h"
#include"Game.h"
#include"PauseState.h"
#include"Player.h"
#include"Enemy.h"
#include"LoaderParams.h"
#include"TextureManager.h"
#include"InputHandler.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
    if (TheInputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheGame::getInstance()->getGameStateMachine()->pushState(new PauseState());
    }

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
    Game* game = TheGame::getInstance();
    TextureManager* textureManager = TheTextureManager::getInstance();

    if (!textureManager->load("assets/helicopter.png", "helicopter", game->getRenderer())) {
        return false;
    }

    if (!textureManager->load("assets/helicopter2.png", "helicopter2", game->getRenderer())) {
        return false;
    }

    GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
    GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

    gameObjects.push_back(player);
    gameObjects.push_back(enemy);

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
