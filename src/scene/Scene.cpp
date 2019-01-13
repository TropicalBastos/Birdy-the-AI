#include "Scene.h"
#include <iostream>

void Scene::add(Object* obj)
{
    m_grid.add(obj);
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