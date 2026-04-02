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
	player->update(dt);
}

void Game::render(sf::RenderWindow* window)
{
	window->draw(*backgroundSprite);
	player->render(window);
}
