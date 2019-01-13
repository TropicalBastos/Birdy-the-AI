#include "SceneBuilder.h"
#include "../object/Birdy.h"
#include <iostream>
#include "../grid/Grid.h"

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees) : 
    m_parent(parent),
    m_numTrees(numTrees),
    m_scene(new Scene(parent))
{
    initScene();
}

SceneBuilder::SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees, sf::Sprite background)
    : SceneBuilder(parent, numTrees)
{
    m_scene->setBackground(background);
}

sf::Vector2f SceneBuilder::randomPos() const
{
    int min = 80;
    int maxX = m_parent->getSize().x - min;
    int maxY = m_parent->getSize().y - min;
    int x = rand() % (maxX - min + 1) + min;
    int y = rand() % (maxY - min + 1) + min;
    return sf::Vector2f(x, y);
}

TilePosition SceneBuilder::getNextFreeTile() const {
    Grid& grid = m_scene->getGrid();
    bool isTileFree = false;
    Tile foundTile;
    for(auto tileVector : *(grid.getTileMatrix()))
    {
        for(auto tile : tileVector)
        {
            if(tile.isOccupied()) continue;
            foundTile = tile;
            isTileFree = true;
            goto endloop;
        }
    }
    endloop:
    if(isTileFree) {
        return foundTile.getPos();
    }
    // if no tiles free then return the position of the first tile
    return TilePosition{ 0, 0 };
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
    TilePosition randpos = getNextFreeTile();
    Birdy* birdy = new Birdy(m_parent, { 0, 0 }, randomSpeed());
    m_scene->add(birdy);
    for(int i = 0; i < m_numTrees; i++)
    {
        randpos = getNextFreeTile();
        std::cout << "tile x: " << randpos.x << " tile y: " << randpos.y << std::endl;
        // the below means there are no more free tiles so exit the loop
        if(randpos.x == 0) break;
        m_scene->add(new Object(m_parent, sf::Vector2f(randpos.x, randpos.y), 0, "res/sprites/tree.png"));
    }
}