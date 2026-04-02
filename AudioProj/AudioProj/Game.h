#pragma once
#include "SFML/Graphics.hpp"
#include "PLayer.h"

class Game
{
public:

	Game();
	~Game();

	void handleInput(float dt);
	void update(float dt);
	void render(sf::RenderWindow* wind);

private:

	Player* player;
	sf::Texture* backgroundTexture;
	sf::Sprite* backgroundSprite;
};

