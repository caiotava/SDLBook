#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include<iostream>
#include<vector>
#include"GameState.h"
#include"GameObject.h"

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

        static void menuToPlay();
        static void exitFromMenu();

        std::vector<GameObject*> gameObjects;
};

#endif
