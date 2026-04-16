#include "PowerUp.h"
#include <cstdlib>
#include <ctime>

PowerUp::PowerUp()
{
	powerupTexture = new sf::Texture("Assets/powerup.png");
	powerupSprite = new sf::Sprite(*powerupTexture);
	powerupSprite->setPosition(sf::Vector2f(-200.0f, -0.0f));

	powerupSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 50, 50 }));

	powerupSprite->setScale(sf::Vector2f(1.0f, 1.0f));

	velocity = sf::Vector2f(0.0f, 200.0f);

	pTime = 0;

	srand(time(0));

}

PowerUp::~PowerUp()
{
	
}

void PowerUp::update(float dt)
{
	powerupSprite->setPosition(sf::Vector2f(powerupSprite->getPosition().x, powerupSprite->getPosition().y + (speed * dt) ));
	pTime = pTime + dt;

	if (pTime > 15)
	{
		pTime = 0;
		int randInt = rand() % 500 + 0;

		powerupSprite->setPosition(sf::Vector2f(randInt, -100.0f));
	}
}

void PowerUp::render(sf::RenderWindow* window)
{
	window->draw(*powerupSprite);
}

void PowerUp::resetPowerup()
{
	powerupSprite->setPosition(sf::Vector2f(-200.0f, -0.0f));
}