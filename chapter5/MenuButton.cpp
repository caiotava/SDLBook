#include"MenuButton.h"
#include"InputHandler.h"

MenuButton::MenuButton(const LoaderParams *pParams, void (*pOnClickEvent)()): SDLGameObject(pParams), onClickEvent(pOnClickEvent)
{
    currentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
    SDLGameObject::draw();
}

void MenuButton::update()
{
    Vector2D *mousePos = TheInputHandler::getInstance()->getMousePosition();
    currentFrame = MOUSE_OUT;
    released = true;

    if (mousePos->getX() < (position.getX() + width)
        && mousePos->getX() > position.getX()
        && mousePos->getY() < (position.getY() + height)
        && mousePos->getY() > position.getY()) {
        currentFrame = MOUSE_OVER;

        if (TheInputHandler::getInstance()->getMouseButtonState(LEFT) && released) {
            currentFrame = CLICKED;
            onClickEvent();
            released = false;
        }
    }
}
