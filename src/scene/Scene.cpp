#include "Scene.h"
#include <iostream>

Scene::~Scene()
{
    for(auto obj : m_objects)
    {
        delete obj;
    }
}

unsigned int Scene::add(Object* obj)
{
    m_objects.push_back(obj);
    return m_objects.size() - 1;
}

void Scene::remove(unsigned int index)
{
    m_objects.erase(m_objects.begin() + index);
}

void Scene::draw() const
{
    m_parent->clear();
    for(auto obj : m_objects)
    {
        obj->draw();
    }
    m_parent->display();
}