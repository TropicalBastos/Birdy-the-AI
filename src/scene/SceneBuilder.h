#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "Scene.h"
#include "../grid/Tile.h"

class SceneBuilder {

    public:
        SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees);
        SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees, sf::Sprite background);
        ~SceneBuilder();
        sf::Vector2f randomPos() const;
        TilePosition getNextFreeTile() const;
        TilePosition getRandomFreeTile() const;
        inline Scene* getScene() const { return m_scene; }

    private:
        Scene* m_scene;
        sf::RenderWindow* m_parent;
        int m_numTrees;
        void initScene();


};

#endif