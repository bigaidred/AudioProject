#include "Player.h"

Player::Player()
{
	playerTexture = new sf::Texture("Assets/player.png");
	invincibleTexture = new sf::Texture("Assets/invincible.png");
	playerSprite = new sf::Sprite(*playerTexture);
	playerSprite->setPosition(sf::Vector2f(100.0f, 350.0f));

	playerSprite->setTextureRect(sf::IntRect({ 0, 0 }, { 50, 50 }));

	playerSprite->setScale(sf::Vector2f(1.0f, 1.0f));

	velocity = sf::Vector2f(0.0f, 0.0f);

	timer = 0;
	health = 3;
	invincible = false;
}

Player::~Player()
{

}

void Player::update(float dt)
{
	if (invincible)
	{
		timer = timer + dt;

		if (timer >= 2.0f)
		{
			invincible = false;
			playerSprite->setTexture(*playerTexture);
			timer = 0.0f;
		}
	}

	playerSprite->setPosition(playerSprite->getPosition() + (velocity * dt));

	if (playerSprite->getPosition().y < 0.0f)
	{
		playerSprite->setPosition(sf::Vector2f(playerSprite->getPosition().x, 0.0f));
	}

	if (playerSprite->getPosition().x < 0.0f)
	{
		playerSprite->setPosition(sf::Vector2f(0.0f, playerSprite->getPosition().y));
	}

	if (playerSprite->getPosition().y > 600.0f)
	{
		playerSprite->setPosition(sf::Vector2f(playerSprite->getPosition().x, 600.0f));
	}

	if (playerSprite->getPosition().x > 600.0f)
	{
		playerSprite->setPosition(sf::Vector2f(600.0f, playerSprite->getPosition().y));
	}
	
}

void Player::handleInput(float dt)
{
	input = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocity.x = speed;
		input = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocity.x = -speed;
		input = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		velocity.y = -speed;
		input = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		velocity.y = speed;
		input = true;
	}

	if(!input)
	{
		velocity = sf::Vector2f(0.0f, 0.0f);
	}
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(*playerSprite);
}