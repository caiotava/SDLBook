//
// Created by caiotava on 4/25/21.
//

#ifndef SDLBOOK_CMAKE_LAYER_H
#define SDLBOOK_CMAKE_LAYER_H

class Layer {
public:
    virtual void render() = 0;
    virtual void update() = 0;

protected:
    virtual ~Layer() {}
};

#endif //SDLBOOK_CMAKE_LAYER_H
