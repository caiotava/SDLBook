//
// Created by caiotava on 4/25/21.
//

#include "ObjectLayer.h"

void ObjectLayer::update() {
    for (auto& o : objects) {
        o->update();
    }
}

void ObjectLayer::render() {
    for (auto& o : objects) {
        o->draw();
    }
}