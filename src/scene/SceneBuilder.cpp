#include "SceneBuilder.h"
#include "../object/Birdy.h"
#include <iostream>

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees) : 
    m_parent(parent),
    m_numTrees(numTrees),
    m_scene(new Scene(parent))
{
    initScene();
}

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees, bool doNotInitScene) : 
    m_parent(parent),
    m_numTrees(numTrees),
    m_scene(new Scene(parent))
{
    if(!doNotInitScene){
        initScene();
    }
}

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees, sf::Sprite background)
    : SceneBuilder(parent, numTrees, true)
{
    m_scene->add(new Object(parent, {0,0}, 0, background));
    initScene();
}

sf::Vector2f SceneBuilder::randomPos() const
{
    int min = 80;
    int maxX = m_parent->getSize().x - min;
    int maxY = m_parent->getSize().y - min;
    int x = rand() % (maxX - min + 1) + min;
    int y = rand() % (maxY - min + 1) + min;
    std::cout << "Generated x and y are: " << x << "," << y << std::endl;
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

void SceneBuilder::initScene()
{
    Birdy* birdy = new Birdy(m_parent, randomPos(), randomSpeed());
    m_scene->add(birdy);
    for(int i = 0; i < m_numTrees; i++)
    {
        m_scene->add(new Object(m_parent, randomPos(), 0, "res/sprites/tree.png"));
    }
}