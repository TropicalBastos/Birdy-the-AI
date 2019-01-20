#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../object/Birdy.h"
#include <SFML/System.hpp>
#include <iostream>

class Controller
{
    public:
        static void control(sf::Event event, Birdy* bird)
        {
            if(event.KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Down:
                    {
                        bird->setDirection(Birdy::DIRECTION::DOWN);
                        break;
                    }
                    case sf::Keyboard::Up:
                    {
                        bird->setDirection(Birdy::DIRECTION::UP);
                        break;
                    }
                    case sf::Keyboard::Right:
                    {
                        bird->setDirection(Birdy::DIRECTION::RIGHT);
                        break;
                    }
                    case sf::Keyboard::Left:
                    {
                        bird->setDirection(Birdy::DIRECTION::LEFT);
                        break;
                    }
                }
            }
        }
};

#endif