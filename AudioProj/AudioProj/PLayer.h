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

	sf::Sprite* getBody()
	{
		return playerSprite;
	}

	bool isInvincible()
	{
		return invincible;
	}

	void setInvincible(bool i)
	{
		invincible = i;

		if (invincible)
		{
			playerSprite->setTexture(*invincibleTexture);
		}
	}

	bool isPowered()
	{
		return powered;
	}

	void setPowered(bool p)
	{
		powered = p;

		if (powered)
		{
			playerSprite->setTexture(*powerTexture);
		}
	}

private:

	sf::Vector2f velocity;
	float speed = 250.0f;
	bool invincible;
	float timer;
	float invincibleTime = 2.0f;
	int health;
	bool powered;

	sf::Sprite* playerSprite;
	sf::Texture* playerTexture;
	sf::Texture* invincibleTexture;
	sf::Texture* powerTexture;
};

