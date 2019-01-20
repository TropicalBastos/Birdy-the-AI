#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/SceneBuilder.h"
#include "object/Birdy.h"
#include "core/Transition.h"
#include <time.h>
#include <thread>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SETUP_BACKGROUND
    sf::RenderWindow window(sf::VideoMode(backgroundSize.x, backgroundSize.y), APP_NAME);
    SceneBuilder sceneBuilder(&window, 3, backgroundSprite);
    Scene* scene = sceneBuilder.getScene();
    scene->getGrid().enableWireframe();

    int fps = 0;
    sf::Clock clock;
    int lastTime = clock.getElapsedTime().asMilliseconds();
    int tick = lastTime;
    const double MAX_TIME = 1000 / TARGET_FPS;

    while(window.isOpen())
    {
        int now = clock.getElapsedTime().asMilliseconds();
        int diff = now - lastTime;
        lastTime = now;
        tick += diff;
        double delta = MAX_TIME - diff;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(delta > 0)
        {
            Birdy* bird = Birdy::getInstance();
            if(bird->wormEaten)
            {
                birdy::displayTransition(&window, "BIRDY ATE THE WORM, LEARNING...");
                //sceneBuilder.resetScene();
            } 
            else
            {
                bird->move();
                scene->draw();
            }
            fps++;
            std::chrono::milliseconds sleepFor(static_cast<int>(delta));
            std::this_thread::sleep_for(sleepFor);
        }

        if(tick >= 1000)
        {
            std::cout << "FPS: " << fps << std::endl;
            fps = 0;
            tick = 0;
        }
    }

    return EXIT_SUCCESS;
}