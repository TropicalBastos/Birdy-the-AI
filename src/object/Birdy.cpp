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
    resetOriginIfNecessary();
    if(direction != DIRECTION::UP){
        direction = DIRECTION::UP;
        m_drawable.setRotation(45);
    }
    m_pos.y -= m_speed;
}

void Birdy::moveDown()
{
    resetOriginIfNecessary();
    if(direction != DIRECTION::DOWN){
        direction = DIRECTION::DOWN;
        m_drawable.setRotation(270);
    }
    m_pos.y += + m_speed;
}

void Birdy::moveLeft()
{
    resetOriginIfNecessary();
    if(direction != DIRECTION::LEFT){
        direction = DIRECTION::LEFT;
        m_drawable.setRotation(0);
    }
    m_pos.x -= m_speed;
}

void Birdy::moveRight()
{
    if(direction != DIRECTION::RIGHT){
        direction = DIRECTION::RIGHT;
        m_drawable.scale(-1, 1);
        m_pos.x += getWidth();
    }
    m_pos.x += m_speed;

}

void Birdy::move()
{
    moveRight();
}

void Birdy::resetOriginIfNecessary()
{
    if(direction != DIRECTION::RIGHT){
        m_pos.x -= getWidth();
        m_drawable.scale(1, 1);
    }
}