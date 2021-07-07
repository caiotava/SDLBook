//
// Created by caiotava on 4/28/21.
//

#ifndef SDLBOOK_CMAKE_COLLISION_H
#define SDLBOOK_CMAKE_COLLISION_H

#include<SDL.h>

const static int buffer = 4;

static bool RectRect(SDL_Rect* A, SDL_Rect* B) {
    int aHBuf = A->h / buffer;
    int aWBuf = A->w / buffer;

    int bHBuf = B->h / buffer;
    int bWBuf = B->w / buffer;

    if ((A->y + A->h) - aHBuf <= B->y + bHBuf) {
        return false;
    }

    if ((A->y + aHBuf) >= (B->y + B->h) - bHBuf) {
        return false;
    }

    if ((A->x + A->w) - aWBuf <= B->x + bWBuf) {
        return false;
    }

    if (A->x + aWBuf) <= (B->x + B->w) - bWBuf) {
        return false;
    }

    return true;
}

#endif //SDLBOOK_CMAKE_COLLISION_H
