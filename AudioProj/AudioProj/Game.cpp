#include "Game.h"
#include <iostream>

Game::Game()
{
	score = 0;
	scoreMult = 1;
	timer = 0.0f;
	
	player = new Player();

	backgroundTexture = new sf::Texture("Assets/background.png");
	backgroundTexture->setRepeated(true);
	backgroundSprite = new sf::Sprite(*backgroundTexture);

	backgroundSprite->setPosition(sf::Vector2f(0.0f, 0.0f));

	backgroundSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 700, 700 }));

	backgroundSprite->setScale(sf::Vector2f(1.0f, 1.0f));

	for (int i = 0; i < 3; i++)
	{
		obstacles.push_back(new Obstacle(i));
	}

	if (!font.openFromFile("Assets/impact.ttf"))
	{
		std::cout << "hrmm" << std::endl;
	};

	scoreText = new sf::Text(font, "Score:" + std::to_string(score));

	scoreText->setFillColor(sf::Color::Red);

	scoreText->setPosition(sf::Vector2f(10.0f, 20.0f));

	scoreText->setCharacterSize(36);

	soundManager = new SoundManager();
	powerup = new PowerUp();
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
	timer = timer + dt;

	player->update(dt);
	powerup->update(dt);

	if (timer >= 1)
	{
		score = score + scoreMult;
		scoreMult++;
		timer = 0;
		scoreText->setString("Score:" + std::to_string(score));
	}
	
	sf::FloatRect playerBody = player->getBody()->getGlobalBounds();

	bool coll = false;

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->update(dt);

		if (player->isInvincible() == false && player->isPowered() == false)
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
		score = 0;
		scoreMult = 1;
		scoreText->setString("Score:" + std::to_string(score));

		for (int i = 0; i < obstacles.size(); i++)
		{
			obstacles[i]->resetSpeed();
		}
	}

	if (player->isInvincible() == false && player->isPowered() == false)
	{
		sf::FloatRect obstacleBody = powerup->getBody()->getGlobalBounds();

		if (const std::optional intersect = playerBody.findIntersection(obstacleBody))
		{
			player->setPowered(true);
			powerup->resetPowerup();
		}
	}

	soundManager->updateMusic(score, player->isPowered());
	
}

void Game::render(sf::RenderWindow* window)
{
	window->draw(*backgroundSprite);
	player->render(window);
	powerup->render(window);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->render(window);
	}

	window->draw(*scoreText);
}
