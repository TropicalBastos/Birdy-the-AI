#ifndef TRANSITION_H
#define TRANSITION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <thread>
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
        text.setFillColor(sf::Color(255, 255, 255, 100));
        text.setFont(font);

        uint32_t localTextBoundsWidth = text.getLocalBounds().width;
        uint32_t localTextBoundsHeight = text.getLocalBounds().height;
        text.setPosition((windowSize.x / 2) - localTextBoundsWidth / 2, (windowSize.y / 2) - localTextBoundsHeight / 2);

        parent->draw(rect);
        parent->draw(text);
        parent->display();
    }
}

#endif