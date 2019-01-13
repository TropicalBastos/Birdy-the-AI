#define APP_NAME "Birdy the AI"
#define DEFAULT_SCREEN_WIDTH 800
#define DEFAULT_SCREEN_HEIGHT 600

#define SETUP_BACKGROUND \
    sf::Texture background;\
    background.loadFromFile("res/textures/background.jpg");\
    sf::Vector2u backgroundSize = background.getSize();\
    sf::Sprite backgroundSprite(background);