#ifndef CONFIG_H
#define CONFIG_H

#define APP_NAME "Birdy the AI"
#define TARGET_FPS 60
#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600

#define SETUP_BACKGROUND \
    sf::Texture background;\
    background.loadFromFile("res/textures/background.jpg");\
    sf::Vector2u backgroundSize = background.getSize();\
    sf::Sprite backgroundSprite(background);

#define TREE_TEXTURE "res/sprites/tree.png"
#define BIRDY_TEXTURE "res/sprites/bird/birdy-right.png"
#define WORM_TEXTURE "res/sprites/worm.png"
#define DEFAULT_BIRDY_SPEED 4

#define console(x) std::cout << x << std::endl;

#define TRANSITION_TIME 3000

#endif