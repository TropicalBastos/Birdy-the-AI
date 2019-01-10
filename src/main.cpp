#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/Scene.h"
#include "object/Birdy.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APP_NAME);
    Scene scene(&window);

    sf::Texture texture;
    texture.loadFromFile("res/texture/player.png");
    sf::Sprite playerSprite(texture);
    Birdy birdy(&window, sf::Vector2f(0, 0), 0.5f, playerSprite);
    birdy.setPos(sf::Vector2f((SCREEN_WIDTH / 2) - (birdy.getWidth() / 2), (SCREEN_HEIGHT / 2) - (birdy.getHeight() / 2)));
    unsigned int playerIndex = scene.add(&birdy);

    while(window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        scene.draw();
    }

    return EXIT_SUCCESS;
}