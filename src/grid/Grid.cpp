#include "Grid.h"
#include <iostream>

Grid::Grid(sf::RenderWindow* parent, unsigned int columns, unsigned int rows) : 
    m_parent(parent),
    columns(columns),
    rows(rows)
{
    int width = parent->getSize().x;
    int height = parent->getSize().y;
    float tileWidth = width / columns;
    float tileHeight = height / rows;
    for(int i = 0; i < rows; i++)
    {
        m_tileMatrix.push_back(TileVector());
        for(int j = 0; j < columns; j++)
        {
            m_tileMatrix[i].push_back(Tile({tileWidth, tileHeight}));
        }
    }
}

void Grid::draw() const
{
    int row = 0;
    for(auto tileRows : m_tileMatrix)
    {
        int column = 0;
        for(auto currentTile : tileRows)
        {
            sf::RectangleShape tile;
            TileDimensions dim = currentTile.getDimensions();
            tile.setSize({dim.width, dim.height});
            tile.setPosition(dim.width * column, dim.height * row);
            tile.setFillColor(sf::Color(0, 0, 0, 0));
            tile.setOutlineColor(sf::Color(0, 0, 0, 100));
            tile.setOutlineThickness(1.0f);
            m_parent->draw(tile);
            column++;
        }
        row++;
    }
}