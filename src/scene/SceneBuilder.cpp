#include "SceneBuilder.h"
#include "../object/Birdy.h"
#include "../config.h"

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees)
{
    m_parent = parent;
    m_scene = new Scene(m_parent);
    Birdy* birdy = new Birdy(m_parent, randomPos(), randomSpeed());
    m_scene->add(birdy);
    for(int i = 0; i < numTrees; i++)
    {
        m_scene->add(new Object(m_parent, randomPos(), 0, "res/sprites/tree.png"));
    }
}

sf::Vector2f SceneBuilder::randomPos() const
{
    int x = rand() % SCREEN_WIDTH;
    int y = rand() % SCREEN_HEIGHT;
    return sf::Vector2f(x, y);
}

float SceneBuilder::randomSpeed() const
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

SceneBuilder::~SceneBuilder()
{
    delete m_scene;
}