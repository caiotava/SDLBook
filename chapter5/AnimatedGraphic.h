#ifndef __ANIMATEDGRAPHIC_H__
#define __ANIMATEDGRAPHIC_H__

#include"SDLGameObject.h"
#include"LoaderParams.h"

class AnimatedGraphic: public SDLGameObject
{
    public:
        AnimatedGraphic(const LoaderParams* pParams, int animateSpeed);

        virtual void draw();
        virtual void update();
        virtual void clean() {}

    private:
        int animateSpeed;
};

#endif
