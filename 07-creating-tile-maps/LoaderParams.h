//
// Created by caiotava on 4/17/21.
//

#ifndef SDLBOOK_CMAKE_LOADERPARAMS_H
#define SDLBOOK_CMAKE_LOADERPARAMS_H

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID, int frames = 0, int callbackID = 0, int animateSpeed = 0) :
            x(x), y(y), width(width), height(height), textureID(textureID), frames(frames), callbackID(callbackID), animateSpeed(animateSpeed) {
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getNumberFrames() const { return frames; }
    int getCallbackID() const { return callbackID; }
    int getAnimateSpeed() const { return animateSpeed; }
    std::string getTextureID() const { return textureID; }
private:
    int x;
    int y;
    int width;
    int height;
    int frames;
    int callbackID;
    int animateSpeed;

    std::string textureID;
};

#endif //SDLBOOK_CMAKE_LOADERPARAMS_H
