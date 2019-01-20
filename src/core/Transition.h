#ifndef TRANSITION_H
#define TRANSITION_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../scene/Scene.h"

namespace birdy
{
    void displayTransition(sf::RenderWindow* parent, const std::string& str)
    {
        using namespace std::chrono;
        sf::Font font;
        font.loadFromFile("res/fonts/code.otf");
        parent->clear();
        sf::RectangleShape rect;
        sf::Vector2u windowSize = parent->getSize();
        rect.setSize(static_cast<sf::Vector2f>(windowSize));
        rect.setPosition(0, 0);
        rect.setFillColor(sf::Color(0, 0, 0, 100));
        sf::Text text;
        text.setString(str);
        text.setPosition(windowSize.x / 4, windowSize.y / 2);
        text.setFillColor(sf::Color(255, 255, 255, 100));
        text.setCharacterSize(20);
        text.setFont(font);
        parent->draw(rect);
        parent->draw(text);
        parent->display();
    }
}

#endif