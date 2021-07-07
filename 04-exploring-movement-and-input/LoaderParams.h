//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_LOADERPARAMS_H
#define SDLBOOK_CMAKE_LOADERPARAMS_H

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) :
            x(x), y(y), width(width), height(height), textureID(textureID) {
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getTextureID() const { return textureID; }
private:
    int x;
    int y;
    int width;
    int height;

    std::string textureID;
};

#endif //SDLBOOK_CMAKE_LOADERPARAMS_H
