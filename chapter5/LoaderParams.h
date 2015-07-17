#ifndef __LOADERPARAMS_H__
#define __LOADERPARAMS_H__

#include<iostream>

class LoaderParams
{
    public:
        LoaderParams(int pX, int pY, int pWidth, int pHeight, std::string pTextureId):
            x(pX), y(pY), width(pWidth), height(pHeight), textureId(pTextureId) {}

        int getX() const { return x; }
        int getY() const { return y; }
        int getWidth() const { return width; }
        int getHeight() const { return height; }

        std::string getTextureId() const { return textureId; }

    private:
        int x;
        int y;
        int width;
        int height;

        std::string textureId;
};

#endif
