#include "Birdy.h"
#include "../core/Time.h"

Birdy* Birdy::instance = nullptr;

Birdy::Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed) : 
    Object(window, pos, speed, BIRDY_TEXTURE),
    direction(DIRECTION::NONE)
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
    if(direction == NONE)
    {
        setDirection(DIRECTION::RIGHT);
    }

    checkBoundaries();

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
        case DIRECTION::NONE:
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
        case DIRECTION::NONE:
            setDirection(DIRECTION::NONE);
            break;
    }
}

void Birdy::setDirection(DIRECTION dir)
{
    if(dir == DIRECTION::RIGHT && (direction != DIRECTION::UP && direction != DIRECTION::DOWN))
    {
        m_drawable.scale(-1, 1);
        m_pos.x += getWidth();
    }
    else if(dir == DIRECTION::LEFT && (direction != DIRECTION::UP && direction != DIRECTION::DOWN))
    {
        m_pos.x -= getWidth();
        m_drawable.scale(-1, 1);
    }
    direction = dir;
}

void Birdy::checkBoundaries()
{
    if(abs(directionChanged - birdy::Time::timestamp()) < 2)
    {
        return;
    }
    float width = getWidth();
    float height = getHeight();
    sf::Vector2u windowSize = m_parent->getSize();
    if(
        m_pos.x + width >= windowSize.x ||
        m_pos.y + height >= windowSize.y ||
        m_pos.x <= 0 ||
        m_pos.y <= 0
    ){
        flipDirection();
        directionChanged = birdy::Time::timestamp();
    }
}