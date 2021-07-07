//
// Created by caiotava on 4/27/21.
//

#ifndef SDLBOOK_CMAKE_SCROLLINGBACKGROUND_H
#define SDLBOOK_CMAKE_SCROLLINGBACKGROUND_H

#include "ShooterObject.h"

class ScrollingBackground : SDLGameObject {
public:
    ScrollingBackground();

    void draw();

    void update();

    void load(std::unique_ptr<LoaderParams> const &params);

private:
    void initRects();

    int scrollSpeed;
    int count;
    int maxCount;

    SDL_Rect srcRect1;
    SDL_Rect srcRect2;

    SDL_Rect destRect1;
    SDL_Rect destRect2;

    int destRect1Width;
    int destRect2Width;

    int srcRect1Width;
    int srcRect2Width;
};


#endif //SDLBOOK_CMAKE_SCROLLINGBACKGROUND_H
