#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "Scene.h"
#include "../grid/Tile.h"
#include <memory>

class SceneBuilder {

    public:
        SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees);
        SceneBuilder(sf::RenderWindow* parent, unsigned int numTrees, sf::Sprite background);
        ~SceneBuilder(){}
        sf::Vector2f randomPos() const;
        TilePosition getNextFreeTile() const;
        TilePosition getRandomFreeTile() const;
        TilePosition getFreeAdjacentTile(int originX, int originY) const;
        inline Scene* getScene() const { return m_scene.get(); }
        void resetScene();

    private:
        std::shared_ptr<Scene> m_scene;
        sf::RenderWindow* m_parent;
        sf::Sprite m_background;
        int m_numTrees;
        void initScene(bool reInit = false);


};

#endif