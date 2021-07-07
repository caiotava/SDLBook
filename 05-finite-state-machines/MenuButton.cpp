//
// Created by caiotava on 4/21/21.
//

#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams *params, void (*callback)()) :
        SDLGameObject(params),
        callback(callback) {
    currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
    SDLGameObject::draw();
}

void MenuButton::update() {
    auto input = InputHandler::Instance();
    Vector2D *mousePos = input->getMousePosition();

    currentFrame = MOUSE_OUT;

    if ((mousePos->getX() < position.getX() + width) &&
        (mousePos->getX() > position.getX()) &&
        (mousePos->getY() < position.getY() + height) &&
        (mousePos->getY() > position.getY())) {

        if (input->getMouseButtonState(LEFT) && released) {
            currentFrame = MOUSER_CLICKED;

            callback();
            released = false;
        } else if (!input->getMouseButtonState(LEFT)) {
            currentFrame = MOUSE_OVER;
            released = true;
        }

        return;
    }
}