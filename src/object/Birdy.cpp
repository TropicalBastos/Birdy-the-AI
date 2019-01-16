#include "Birdy.h"

Birdy* Birdy::instance = nullptr;

Birdy* Birdy::createInstance(sf::RenderWindow* window, sf::Vector2f pos, float speed)
{
    if(instance == nullptr)
    {
        instance = new Birdy(window, pos, speed);
    }
    return instance;
}

void Birdy::moveUp()
{
    m_pos.y -= m_speed;
}

void Birdy::moveDown()
{
    m_pos.y += + m_speed;
}

void Birdy::moveLeft()
{
    m_pos.x -= m_speed;
}

void Birdy::moveRight()
{
    m_pos.x += m_speed;
}

void Birdy::move()
{
    moveDown();
}