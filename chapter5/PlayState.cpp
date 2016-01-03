#include<iostream>
#include"PlayState.h"
#include"Game.h"
#include"TextureManager.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"Player.h"
#include"Enemy.h"
#include"GameOverState.h"

const std::string PlayState::playId = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::getInstance()->getStateMachine()->pushState(new PauseState());
	}

	for (int x = 0; x < gameObjects.size(); x++) {
		gameObjects[x]->update();
	}

    if (checkCollision(dynamic_cast<SDLGameObject*>(gameObjects[0]), dynamic_cast<SDLGameObject*>(gameObjects[1]))) {
        TheGame::getInstance()->getStateMachine()->pushState(new GameOverState());
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

	if (!TheTextureManager::getInstance()->load("assets/helicopter2.png", "helicopter2", TheGame::getInstance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

	gameObjects.push_back(player);
	gameObjects.push_back(enemy);

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

bool PlayState::checkCollision(SDLGameObject* pPlayer, SDLGameObject* pEnemy)
{
	int leftPlayer, leftEnemy;
	int rightPlayer, rightEnemy;
	int topPlayer, topEnemy;
	int bottomPlayer, bottomEnemy;

	leftPlayer = pPlayer->getPosition().getX();
	rightPlayer = leftPlayer + pPlayer->getWidth();
	topPlayer = pPlayer->getPosition().getY();
	bottomPlayer = topPlayer + pPlayer->getHeight();

	leftEnemy = pEnemy->getPosition().getX();
	rightEnemy = leftEnemy + pEnemy->getWidth();
	topEnemy = pEnemy->getPosition().getY();
	bottomEnemy = topEnemy + pEnemy->getHeight();

	return !((bottomPlayer <= topEnemy)
		|| (topPlayer >= bottomEnemy)
		|| (rightPlayer <= leftEnemy)
		|| (leftPlayer >= rightEnemy));
}
