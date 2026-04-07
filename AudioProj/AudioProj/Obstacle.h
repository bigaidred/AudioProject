#pragma once
#include "SFML/Graphics.hpp"

class Obstacle
{
public:

	Obstacle();
	Obstacle(float pos);
	~Obstacle();

	void update(float dt);
	void render(sf::RenderWindow* window);

	void resetSpeed()
	{
		speed = 100.0f;
	}

	sf::Sprite* getBody()
	{
		return obstacleSprite;
	}

private:

	sf::Texture* obstacleTexture;
	sf::Sprite* obstacleSprite;
	
	float speed = 100.0f;
	float speedMultiplier = 5.0f;
	float multiplierIncrement = 1.5f;
	float spawnOffset = -250.0f;
};

