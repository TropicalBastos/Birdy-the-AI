#include "Scene.h"
#include "../object/ObjectInterface.h"
#include "../object/Object.h"
#include <iostream>

void Scene::add(ObjectInterface* obj, bool beginning)
{
    obj->setScene(this);
    m_grid.add(obj, beginning);
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
    TileMatrix* matrix = m_grid.getTileMatrix();
    for(int i = 0; i < matrix->size(); i++)
    {
        TileVector* vecPtr = &matrix->at(i);
        for(int j = 0; j < vecPtr->size(); j++)
        {
            Tile* tilePtr = &vecPtr->at(j);
            tilePtr->setObject(new Object());
            tilePtr->unoccupy();
        }
    }
}