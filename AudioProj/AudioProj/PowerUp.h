#include "SFML/Graphics.hpp"

class PowerUp
{
public:

	PowerUp();
	~PowerUp();

	void update(float dt);
	void render(sf::RenderWindow* window);

	sf::Sprite* getBody()
	{
		return powerupSprite;
	}

	void resetPowerup();

private:

	sf::Vector2f velocity;
	float speed = 250.0f;

	sf::Sprite* powerupSprite;
	sf::Texture* powerupTexture;
	float pTime;
};

