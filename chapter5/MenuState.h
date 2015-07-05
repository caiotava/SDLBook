#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include<iostream>
#include<vector>
#include"GameState.h"

class MenuState : public GameState
{
    public:
        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateId() const { return menuId; }

    private:
        static const std::string menuId;

        std::vector<GameObject*> gameObject;
};

#endif
