#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/SceneBuilder.h"

int main(int argc, char* argv[])
{
    SETUP_BACKGROUND
    sf::RenderWindow window(sf::VideoMode(backgroundSize.x, backgroundSize.y), APP_NAME);
    SceneBuilder sceneBuilder(&window, 3, backgroundSprite);

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
        sceneBuilder.getScene()->draw();
    }

    return EXIT_SUCCESS;
}