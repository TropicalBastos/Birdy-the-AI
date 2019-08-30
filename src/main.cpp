#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "scene/SceneBuilder.h"
#include "object/Birdy.h"
#include "core/Controller.h"
#include "core/Transition.h"
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
        bool transition = false;
        int transitionStart = 0;

        int fps = 0;
        sf::Clock clock;
        int lastTime = clock.getElapsedTime().asMilliseconds();
        int tick = lastTime;
        const double MAX_TIME = 1000 / TARGET_FPS;

        while (window.isOpen())
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
                {
                    window.close();
                }
                else
                {
                    Controller::dispatch(event, Birdy::getInstance());
                }
            }

            if (delta > 0)
            {
                if (Birdy::getInstance()->wormEaten)
                {
                    if (!transition)
                    {
                        if (Birdy::getInstance()->numWormsEaten > 2)
                        {
                            sceneBuilder.resetScene();
                            Birdy::getInstance()->wormEaten = false;
                        }
                        else
                        {
                            if (Birdy::getInstance()->numWormsEaten == 1)
                            {
                                birdy::displayTransition(&window, "BIRDY ATE THE WORM, LEARNING...");
                            }
                            else if (Birdy::getInstance()->numWormsEaten == 2)
                            {
                                birdy::displayTransition(&window, "BIRDY NOW KNOWS WHERE TO LOOK");
                            }

                            transition = true;
                            transitionStart = clock.getElapsedTime().asMilliseconds();
                        }
                    }
                    else if (transition && (now - transitionStart) > TRANSITION_TIME)
                    {
                        transition = false;
                        transitionStart = 0;
                        sceneBuilder.resetScene();
                        Birdy::getInstance()->wormEaten = false;
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

            if (tick >= 1000)
            {
                //std::cout << "FPS: " << fps << std::endl;
                fps = 0;
                tick = 0;
            }
        }
    }

    return EXIT_SUCCESS;
}