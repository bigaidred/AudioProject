
#include <SFML\Graphics.hpp>
#include "Game.h"
#include "fmod.hpp"
#include <iostream>

int main() {

	//FMOD_RESULT result;
	//FMOD::System* system = nullptr;

	//result = FMOD::System_Create(&system);

	//system->init(32, FMOD_INIT_NORMAL, nullptr);

	//FMOD::Sound* sound = nullptr;
	//system->createSound(R"(Assets/Audio/FullMix.wav)", FMOD_DEFAULT, nullptr, &sound);

	//FMOD::Channel* channel = nullptr;
	//result = system->playSound(sound, nullptr, false, &channel);

	//if (result == FMOD_OK)
	//{
	//	std::cout << "ourgh" << std::endl;
	//}

	// Prepare window.
	sf::RenderWindow window(sf::VideoMode({ 650, 650 }), "Audio Project");

	// Clock for timing the 'dt' value.
	sf::Clock clock;
	Game game;
	
	// Custom clear colour for the window (light blue).
	sf::Color clear_colour(135, 206, 250);

	while (window.isOpen()) {
		// Calculate dt.
		float dt = clock.restart().asSeconds();

		// Handle window events (e.g. key press).
		while (const std::optional event = window.pollEvent()) {
			// This event is triggered when the "x" button is pressed to close the window.
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			// This event checks key press and closes the window on "ESC".
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			}
		}

		window.clear(clear_colour);

		game.handleInput(dt);
		game.update(dt);
		game.render(&window);

		// Render you game objects here

		window.display();
	}
	return 0;
}

