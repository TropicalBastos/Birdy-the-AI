#include "Birdy.h"

Birdy* Birdy::instance = nullptr;

Birdy::Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed) : 
    Object(window, pos, speed, BIRDY_TEXTURE),
    direction(static_cast<DIRECTION>(NULL))
{}

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
    m_drawable.setRotation(45);
    m_pos.y -= m_speed;
}

void Birdy::moveDown()
{
    m_drawable.setRotation(270);
    m_pos.y += + m_speed;
}

void Birdy::moveLeft()
{
    m_drawable.setRotation(0);
    m_pos.x -= m_speed;
}

void Birdy::moveRight()
{
    m_pos.x += m_speed;
}

void Birdy::move()
{
    if(direction == NULL)
    {
        setDirection(DIRECTION::RIGHT);
    }
    switch(direction)
    {
        case DIRECTION::LEFT:
            moveLeft();
            break;
        case DIRECTION::RIGHT:
            moveRight();
            break;
        case DIRECTION::UP:
            moveUp();
            break;
        case DIRECTION::DOWN:
            moveDown();
            break;
    }
}

void Birdy::flipDirection()
{
    switch(direction)
    {
        case DIRECTION::LEFT:
            setDirection(DIRECTION::RIGHT);
            break;
        case DIRECTION::RIGHT:
            setDirection(DIRECTION::LEFT);
            break;
        case DIRECTION::UP:
            setDirection(DIRECTION::DOWN);
            break;
        case DIRECTION::DOWN:
            setDirection(DIRECTION::UP);
            break;
    }
}

void Birdy::setDirection(DIRECTION dir)
{
    if(dir == DIRECTION::RIGHT)
    {
        m_drawable.scale(-1, 1);
        m_pos.x += getWidth();
    }
    else if(direction == DIRECTION::RIGHT)
    {
        m_pos.x -= getWidth();
        m_drawable.scale(1, 1);
    }
    direction = dir;
}