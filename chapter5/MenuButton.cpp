#include"MenuButton.h"
#include"InputHandler.h"

MenuButton::MenuButton(const LoaderParams *pParams): SDLGameObject(pParams)
{
    currentFrame = MOUSE_OUT;
}

void MenuButton::update()
{
    Vector2D *mousePos = TheInputHandler::getInstance()->getMousePosition();
    currentFrame = MOUSE_OUT;

    if (mousePos->getX() < (position.getX() + width)
        && mousePos->getX() > position.getX()
        && mousePos->getY() < (position.getY() + height)
        && mousePos->getY() > position.getY()) {
        currentFrame = MOUSE_OVER;

        if (TheInputHandler::getInstance()->getMouseButtonState(LEFT)) {
            currentFrame = CLICKED;
        }
    }
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}
