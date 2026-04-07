#include "Game.h"

Game::Game()
{
	player = new Player();

	backgroundTexture = new sf::Texture("Assets/background.png");
	backgroundTexture->setRepeated(true);
	backgroundSprite = new sf::Sprite(*backgroundTexture);

	backgroundSprite->setPosition(sf::Vector2f(0.0f, 0.0f));

	backgroundSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 700, 700 }));

	backgroundSprite->setScale(sf::Vector2f(1.0f, 1.0f));

	for (int i = 0; i < 5; i++)
	{
		obstacles.push_back(new Obstacle(i));
	}

}

Game::~Game()
{

}

void Game::handleInput(float dt)
{
	player->handleInput(dt);
}

void Game::update(float dt)
{
	sf::FloatRect playerBody = player->getBody()->getGlobalBounds();

	bool coll = false;

	player->update(dt);


	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->update(dt);

		if (player->isInvincible() == false)
		{
			sf::FloatRect obstacleBody = obstacles[i]->getBody()->getGlobalBounds();

			if (const std::optional intersect = playerBody.findIntersection(obstacleBody))
			{
				coll = true;
			}
		}
	}

	if (coll == true)
	{
		player->setInvincible(true);

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles[i]->resetSpeed();
		}
	}
	
}

void Game::render(sf::RenderWindow* window)
{
	window->draw(*backgroundSprite);
	player->render(window);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->render(window);
	}
}
