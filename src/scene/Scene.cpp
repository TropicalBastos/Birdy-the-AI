#include "Scene.h"
#include "../object/ObjectInterface.h"
#include "../object/Object.h"
#include <iostream>

void Scene::add(ObjectInterface* obj, bool beginning)
{
    obj->setScene(this);
    m_grid.add(obj, beginning);
}

void Scene::remove(unsigned int index)
{
    TileMatrix* matrix = m_grid.getTileMatrix();
    matrix->erase(matrix->begin() + index);
}

void Scene::draw()
{
    m_parent->clear();
    m_parent->draw(m_background);
    m_grid.draw();
    m_parent->display();
}

void Scene::resetObjects()
{
    TileMatrix matrix = *m_grid.getTileMatrix();
    for(TileVector& vec : matrix)
    {
        for(Tile& tile : vec)
        {
            tile.setObject(new Object());
            tile.unoccupy();
        }
    }
}