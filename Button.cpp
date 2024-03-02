//
// Created by cryptic on 28/02/24.
//

#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button(float x, float y, float width, float height, std::string fontPos, std::string buttonText)
        : shape(sf::Vector2f(width, height)){
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green);

    font.loadFromFile(fontPos);
    text.setFont(font);
    text.setString(buttonText);
    text.setPosition(x + 10, y + 10);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);

}

Button::~Button() {

}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    return(mousePos.x >= buttonPos.x &&
            mousePos.x <= buttonPos.x + buttonSize.x &&
            mousePos.y >= buttonPos.y &&
            mousePos.y <= buttonPos.y + buttonSize.y);
}
