//
// Created by caiotava on 4/15/21.
//

#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

#include<SDL_image.h>

Game *Game::instance = 0;

Game *Game::Instance() {
    if (instance == 0) {
        instance = new Game();
    }

    return instance;
}

bool Game::init(const char *title, int xPos, int yPos, int height, int width, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    std::cout << "SDL init success\n";

    int flags = SDL_WINDOW_SHOWN;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if (window == 0) {
        std::cout << "windows creation unsuccessful" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == 0) {
        std::cout << "renderer creation unsuccessful" << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    InputHandler::Instance()->initialiseJoysticks();

    running = true;

    TextureManager::Instance()->load("assets/animate-alpha.png", "rider", renderer);
    TextureManager::Instance()->load("assets/animate-alpha.png", "animate", renderer);

    gameStateMachine = new GameStateMachine();
    gameStateMachine->changeState(new MenuState());

    return true;
}

void Game::handleEvents() {
    auto input = InputHandler::Instance();

    input->update();

    if (input->isKeyDown(SDL_SCANCODE_RETURN)) {
        gameStateMachine->changeState(new PlayState());
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    gameStateMachine->render();

    SDL_RenderPresent(renderer);
}

void Game::update() {
    gameStateMachine->update();
}

void Game::clean() {
    std::cout << "cleaning game" << std::endl;

    running = false;
    InputHandler::Instance()->clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}