#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/SceneBuilder.h"
#include <time.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SETUP_BACKGROUND
    sf::RenderWindow window(sf::VideoMode(backgroundSize.x, backgroundSize.y), APP_NAME);
    SceneBuilder sceneBuilder(&window, 3, backgroundSprite);
    Scene* scene = sceneBuilder.getScene();
    scene->enableGrid(6, 5);

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
        scene->draw();
    }

    return EXIT_SUCCESS;
}