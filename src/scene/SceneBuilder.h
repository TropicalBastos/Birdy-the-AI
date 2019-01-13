#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "Scene.h"

class SceneBuilder {

    public:
        SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees);
        ~SceneBuilder();
        sf::Vector2f randomPos() const;
        float randomSpeed() const;
        inline Scene* getScene() const { return m_scene; }

    private:
        Scene* m_scene;
        sf::RenderWindow* m_parent;

};

#endif