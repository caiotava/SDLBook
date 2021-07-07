//
// Created by caiotava on 4/25/21.
//

#ifndef SDLBOOK_CMAKE_OBJECTLAYER_H
#define SDLBOOK_CMAKE_OBJECTLAYER_H

#include "GameObject.h"
#include "Layer.h"
#include<vector>

class ObjectLayer : public Layer {
public:
    virtual void update();
    virtual void render();

    std::vector<GameObject*>* getGameObjects() { return &objects; }

private:
    std::vector<GameObject*> objects;
};


#endif //SDLBOOK_CMAKE_OBJECTLAYER_H
