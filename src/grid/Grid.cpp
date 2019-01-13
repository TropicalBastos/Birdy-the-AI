#include "Grid.h"
#include <iostream>

Grid::Grid(
    sf::RenderWindow* parent, 
    unsigned int columns, 
    unsigned int rows, 
    std::vector<Object*> objects) : 
        m_parent(parent),
        columns(columns),
        rows(rows),
        wireframe(false)
{
    rebuildTileMatrix();
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
    std::cout << "Positioning object at vertex: " << x << ", " << y << std::endl;
    obj->setPos({ x, y });
}

void Grid::rebuildTileMatrix()
{
    int width = m_parent->getSize().x;
    int height = m_parent->getSize().y;
    float tileWidth = width / columns;
    float tileHeight = height / rows;
    int objectIndex = 0;
    m_tileMatrix = TileMatrix();
    for(unsigned int i = 0; i < rows; i++)
    {
        m_tileMatrix.push_back(TileVector());
        for(unsigned int j = 0; j < columns; j++)
        {
            TileDimensions td{ tileWidth, tileHeight };
            TilePosition tp{ j, i };
            Tile tile(td, tp);
            if(objectIndex < m_objects.size()) {
                Object* obj = m_objects[objectIndex];
                positionObjectInTile(obj, i, j, tileWidth, tileHeight);
                tile.setObject(obj);
                tile.occupy();
                objectIndex++;
            }
            m_tileMatrix[i].push_back(tile);
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
    int matrixSize = m_tileMatrix.size() * m_tileMatrix[0].size();
    if(m_objects.size() == matrixSize) {
        std::cout << "Cannot add anymore tiles, all tiles occupied..." << std::endl;
        return;
    }
    m_objects.push_back(obj);
    rebuildTileMatrix();
}

Grid::~Grid()
{
    std::vector<Object*> objects = getObjects();
    if(objects.size() > 0) 
    {
        for(auto obj : objects)
        {
            delete obj;
        }
    }
}