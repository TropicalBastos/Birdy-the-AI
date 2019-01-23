#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/SceneBuilder.h"
#include "object/Birdy.h"
#include "core/Controller.h"
#include "core/Transition.h"
#include "core/BackgroundThread.h"
#include <time.h>
#include <thread>
#include <memory>
#include <atomic>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SETUP_BACKGROUND
    sf::RenderWindow window(sf::VideoMode(backgroundSize.x, backgroundSize.y), APP_NAME);
    {
        SceneBuilder sceneBuilder(&window, 3, backgroundSprite);
        Scene* scene = sceneBuilder.getScene();
        scene->getGrid().enableWireframe();
        birdy::BackgroundThread backgroundThread;

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
                else
                    Controller::dispatch(event, Birdy::getInstance());
            }

            if(delta > 0)
            {
                if(Birdy::getInstance()->wormEaten)
                {
                    if(!backgroundThread.backgroundThreadCreated)
                    {
                        birdy::displayTransition(&window, "BIRDY ATE THE WORM, LEARNING...");
                        backgroundThread.start(&birdy::birdyTransitionTimer, Birdy::getInstance(), &sceneBuilder);
                        std::cout << "Thread " << backgroundThread.getId() << " has started" << std::endl;
                    }
                } 
                else
                {
                    Birdy::getInstance()->move();
                    sceneBuilder.getScene()->draw();
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
    }

    return EXIT_SUCCESS;
}