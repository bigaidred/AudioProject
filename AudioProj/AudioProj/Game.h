#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Obstacle.h"

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
	sf::Text* scoreText;
	sf::Font font;
	int score;
	int scoreMult;
	float timer;

	std::vector<Obstacle*> obstacles;
};

