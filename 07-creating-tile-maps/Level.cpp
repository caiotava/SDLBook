//
// Created by caiotava on 4/25/21.
//

#include "Level.h"

void Level::render() {
    for (auto &l : layers) {
        l->render();
    }
}

void Level::update() {
    for (auto &l : layers) {
        l->update();
    }
}