#include "Obstacle.h"
#include <cstdlib>
#include <ctime>


Obstacle::Obstacle()
{
	obstacleTexture = new sf::Texture("Assets/obstacle.png");
	obstacleSprite = new sf::Sprite(*obstacleTexture);
	obstacleSprite->setPosition(sf::Vector2f(100.0f, 350.0f));

	obstacleSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 150, 100 }));

	srand(time(0));	

	obstacleSprite->setScale(sf::Vector2f(1.0f, 1.0f));
	obstacleSprite->setPosition(sf::Vector2f(0.0f, 0.0f));

}

Obstacle::Obstacle(float pos)
{
	obstacleTexture = new sf::Texture("Assets/obstacle.png");
	obstacleSprite = new sf::Sprite(*obstacleTexture);
	obstacleSprite->setPosition(sf::Vector2f(100.0f, 350.0f));

	obstacleSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 150, 100 }));

	srand(time(0));

	int randInt = rand() % 500 + 0;

	obstacleSprite->setScale(sf::Vector2f(1.0f, 1.0f));
	obstacleSprite->setPosition(sf::Vector2f(pos*spawnOffset, pos * spawnOffset));

}

Obstacle::~Obstacle()
{

}

void Obstacle::update(float dt)
{
	speed = speed + (speedMultiplier * dt);

	if (speed > 500.0f)
	{
		speed = 500.0f;
	}

	obstacleSprite->setPosition(sf::Vector2f(obstacleSprite->getPosition().x, obstacleSprite->getPosition().y + (speed * dt)));

	if (obstacleSprite->getPosition().y > 650.0f)
	{
		int randInt = rand() % 500 + 0;

		obstacleSprite->setPosition(sf::Vector2f(randInt, spawnOffset));

	}

}

void Obstacle::render(sf::RenderWindow* window)
{
	window->draw(*obstacleSprite);
}
