#include "Grid.h"
#include <iostream>

Grid::Grid(sf::RenderWindow* parent, unsigned int columns, unsigned int rows) : 
        m_parent(parent),
        columns(columns),
        rows(rows),
        wireframe(false)
{
    buildTileMatrix();
}

void Grid::positionObjectInTile(
    Object* obj, 
    unsigned int row, 
    unsigned int column, 
    float width, 
    float height)
{
    if(row == 0) row = 1;
    if(column == 0) column = 1;
    float objWidth = obj->getWidth();
    float objHeight = obj->getHeight();
    float x = ((column * width) - (width / 2)) - (objWidth / 2);
    float y = ((row * height) - (height / 2)) - (objHeight / 2);
    obj->setPos({ x, y });
}

void Grid::buildTileMatrix()
{
    int width = m_parent->getSize().x;
    int height = m_parent->getSize().y;
    float tileWidth = width / columns;
    float tileHeight = height / rows;
    for(unsigned int i = 0; i < rows; i++)
    {
        m_tileMatrix.push_back(TileVector());
        for(unsigned int j = 0; j < columns; j++)
        {
            TileDimensions td{ tileWidth, tileHeight };
            TilePosition tp{ j + 1, i + 1 };
            Tile tile(td, tp);
            m_tileMatrix[i].push_back(tile);
        }
    }
}

void Grid::draw() const
{
    int row = 0;
    for(const TileVector& tileRows : m_tileMatrix)
    {
        int column = 0;
        for(const Tile& currentTile : tileRows)
        {
            if(wireframe) {
                sf::RectangleShape tile;
                TileDimensions dim = currentTile.getDimensions();
                tile.setSize({dim.width, dim.height});
                tile.setPosition(dim.width * column, dim.height * row);
                tile.setFillColor(sf::Color(0, 0, 0, 0));
                tile.setOutlineColor(sf::Color(0, 0, 0, 100));
                tile.setOutlineThickness(1.0f);
                m_parent->draw(tile);
            }
            if(currentTile.isOccupied()){
                currentTile.draw();
            }
            column++;
        }
        row++;
    }
}

void Grid::add(Object* obj)
{
    sf::Vector2f pos = obj->getPos();
    Tile& tile = m_tileMatrix[pos.y - 1][pos.x - 1];
    std::cout << "Occupying tile " << &tile << " at pos " << pos.x << "," << pos.y << std::endl;
    tile.occupy();
    TileDimensions dim = tile.getDimensions();
    positionObjectInTile(obj, pos.y, pos.x, dim.width, dim.height);
    tile.setObject(obj);
}