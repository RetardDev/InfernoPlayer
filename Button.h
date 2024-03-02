//
// Created by cryptic on 28/02/24.
//

#ifndef INFERNOPLAYER_BUTTON_H
#define INFERNOPLAYER_BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

public:
    Button(float x, float y, float width, float height, std::string fontPos, std::string buttonText);
    ~Button();
    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);

};


#endif //INFERNOPLAYER_BUTTON_H
