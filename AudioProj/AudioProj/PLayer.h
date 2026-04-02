#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:

	Player();
	~Player();


	void update(float dt);
	void handleInput(float dt);
	void render(sf::RenderWindow* window);

private:

	sf::Vector2f velocity;
	float speed = 250.0f;
	bool input = false;

	sf::Sprite* playerSprite;
	sf::Texture* playerTexture;
};

