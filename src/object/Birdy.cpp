#include "Birdy.h"
#include "../core/Time.h"
#include <iostream>

Birdy* Birdy::instance = nullptr;

Birdy::Birdy(sf::RenderWindow* window, sf::Vector2f pos, float speed) : 
    Object(window, pos, speed, BIRDY_TEXTURE, Object::TAG::BIRDY),
    direction(DIRECTION::RIGHT),
    wormEaten(false),
    numWormsEaten(0)
{}

Birdy* Birdy::createInstance(sf::RenderWindow* window, sf::Vector2f pos, float speed)
{
    if(instance != nullptr)
    {
        delete instance;
    }
    instance = new Birdy(window, pos, speed);
    return instance;
}

void Birdy::moveUp()
{
    m_pos.y -= m_speed;
}

void Birdy::moveDown()
{
    m_pos.y += m_speed;
}

void Birdy::moveLeft()
{
    m_pos.x -= m_speed;
}

void Birdy::moveRight()
{
    m_pos.x += m_speed;
}

void Birdy::moveInternal()
{
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
        default:
            break;
    }
}

void Birdy::move()
{
    const Tile& tile =  m_scene->getGrid().getTileByAbsolutePosition(m_pos.x, m_pos.y);
    
    if (tile.noTile) 
    {
        flipDirection();
        directionChanged = birdy::Time::timestamp(); 
        moveInternal();
        return;
    }
    else if(abs(directionChanged - birdy::Time::timestamp()) > 0)
    {
        setDirection(ai.decide(tile));
        directionChanged = birdy::Time::timestamp(); 
    }

    checkBoundaries();
    moveInternal();

    if(ai.checkForWorm(tile))
    {
        wormEaten = true;
        ai.learnTile(tile);
        numWormsEaten++;
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
        case DIRECTION::NOWHERE:
            setDirection(DIRECTION::NOWHERE);
            break;
    }
}

void Birdy::setDirection(DIRECTION dir)
{
    if(dir == DIRECTION::LEFT)
    {
        m_texture.loadFromFile("res/sprites/bird/birdy-left.png");
    }
    else if(dir == DIRECTION::RIGHT)
    {
        m_texture.loadFromFile("res/sprites/bird/birdy-right.png");
    }
    else if(dir == DIRECTION::UP)
    {
        m_texture.loadFromFile("res/sprites/bird/birdy-up.png");
    }
    else if(dir == DIRECTION::DOWN)
    {
        m_texture.loadFromFile("res/sprites/bird/birdy-down.png");
    }
    direction = dir;
}

void Birdy::checkBoundaries()
{
    if(abs(directionFlipped - birdy::Time::timestamp()) < 2)
    {
        return;
    }
    float width = getWidth();
    float height = getHeight();
    sf::Vector2u windowSize = m_parent->getSize();
    if(
        m_pos.x + width >= windowSize.x ||
        m_pos.y + height >= windowSize.y ||
        m_pos.x < 1 ||
        m_pos.y < 1
    ){
        flipDirection();
        directionChanged = birdy::Time::timestamp();
        directionFlipped = directionChanged;
    }
}