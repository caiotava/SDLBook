#include<iostream>
#include "Game.h"
#include"TextureManager.h"
#include"LoaderParams.h"
#include"InputHandler.h"
#include"Player.h"
#include"Enemy.h"
#include"MenuState.h"
#include"PlayState.h"

Game *Game::instance = 0;

bool Game::init(const char *title, int xPosition, int yPosition, int height, int width, bool fullScreen)
{
    int flags = SDL_WINDOW_SHOWN;

    if (fullScreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, xPosition, yPosition, height, width, flags);

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        return false;
    }

    gameStateMachine = new GameStateMachine();
    gameStateMachine->changeState(new MenuState());

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    TheInputHandler::getInstance()->initialiseJoysticks();
    TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", renderer);

    Player *player = new Player(new LoaderParams(100, 100, 128, 82, "animate"));
    Enemy *enemy = new Enemy(new LoaderParams(300, 300, 128, 82, "animate"));

    gameObjects.push_back(player);
    gameObjects.push_back(enemy);

    running = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    gameStateMachine->render();

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    InputHandler *inputHandler = TheInputHandler::getInstance();
    inputHandler->update();

    if (inputHandler->isKeyDown(SDL_SCANCODE_RETURN)) {
        gameStateMachine->changeState(new PlayState());
    }
}

void Game::update()
{
    gameStateMachine->update();
}

void Game::clean()
{
    TheInputHandler::getInstance()->clean();

    running = false;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
