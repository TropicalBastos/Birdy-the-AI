#include "SceneBuilder.h"
#include "../object/Birdy.h"
#include <iostream>
#include "../grid/Grid.h"
#include "../config.h"
#include "../core/exception.h"

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
    for(const TileVector& tileVector : *(grid.getTileMatrix()))
    {
        for(const Tile& tile : tileVector)
        {
            std::cout << "Is tile " << &tile << " occupied: " << (tile.isOccupied() ? "true" : "false") << std::endl;
            if(!tile.isOccupied()) return tile.getPos();
        }
    }
    return TilePosition{ 0, 0 };
}

TilePosition SceneBuilder::getFreeAdjacentTile(int originX = 0, int originY = 0) const {
    Grid& grid = m_scene->getGrid();
    if(!grid[originY][originX + 1].isOccupied())
    {
        return grid[originY][originX + 1].getPos();
    }
    else if(!grid[originY + 1][originX].isOccupied())
    {
        return grid[originY + 1][originX].getPos();
    }
    else if(!grid[originY][originX - 1].isOccupied())
    {
        return grid[originY][originX - 1].getPos();
    }
    else if(!grid[originY - 1][originX].isOccupied())
    {
        return grid[originY - 1][originX].getPos();
    }
    else
    {
        throw birdy::occupied_tile_exception();
    }
}

TilePosition SceneBuilder::getRandomFreeTile() const {
    Grid& grid = m_scene->getGrid();
    size_t matrixSize = grid.size();
    int row = rand() % (matrixSize);
    size_t vectorSize = grid[row].size();
    int column = rand() % (vectorSize);
    const Tile& tile = grid[row][column];
    if(tile.isOccupied()) {
        return getRandomFreeTile();
    } else {
        return tile.getPos();
    }
}

SceneBuilder::~SceneBuilder()
{
    delete m_scene;
}

void SceneBuilder::initScene()
{
    bool wormPlaced = false;
    Birdy* bird = Birdy::createInstance(m_parent, { 1 , 1 }, DEFAULT_BIRDY_SPEED);
    m_scene->add(bird);
    for(int i = 0; i < m_numTrees; i++)
    {
        try
        {
            TilePosition randpos = getRandomFreeTile();
            std::cout << "tile x: " << randpos.x << " tile y: " << randpos.y << std::endl;
            m_scene->add(new Object(m_parent, { (float)randpos.x, (float)randpos.y }, 0, TREE_TEXTURE));

            // place worm adjacent to a random tree
            if(!wormPlaced){
                TilePosition adjacentPos = getFreeAdjacentTile(randpos.x, randpos.y);
                m_scene->add(new Object(m_parent, { (float)adjacentPos.x, (float)adjacentPos.y }, 0, WORM_TEXTURE));
                wormPlaced = true;
            }
        } 
        catch(std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}