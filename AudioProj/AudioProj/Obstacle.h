#pragma once
#include "SFML/Graphics.hpp"

class Obstacle
{
public:

	Obstacle();
	~Obstacle();

	void update(float dt);
	void render(sf::RenderWindow* window);

private:

	sf::Texture* obstacleTexture;
	sf::Sprite* obstacleSprite;
};

