//
// Created by caiotava on 4/15/21.
//

#include "Enemy.h"
#include "Game.h"
#include "InputHandler.h"
#include "LoaderParams.h"
#include "Player.h"

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

    auto rider = new Enemy(new LoaderParams(100, 100, 128, 82, "rider"));
    auto player = new Player(new LoaderParams(300, 300, 128, 82, "animate"));

    objects.push_back(rider);
    objects.push_back(player);

    return true;
}

void Game::handleEvents() {
    InputHandler::Instance()->update();
}

void Game::render() {
    SDL_RenderClear(renderer);

    for (auto& obj:objects) {
        obj->draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::update() {
    for (auto& obj:objects) {
        obj->update();
    }
}

void Game::clean() {
    std::cout << "cleaning game" << std::endl;

    running = false;
    InputHandler::Instance()->clean();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}