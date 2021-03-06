#include "stdafx.h"
#include <Windows.h>
#include "Engine.hpp"

int main()
{
	srand(time(NULL));
	FreeConsole();
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Window", sf::Style::Fullscreen);
	window->setMouseCursorVisible(false);
	window->setFramerateLimit(30);
	Engine engine(window);

	sf::Clock clock;
	while (window->isOpen()) {
		sf::Time elapsed = clock.restart();
		engine.updateGame(elapsed);

		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed
				&& event.key.code == sf::Keyboard::Escape) {
				window->close();
			}
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			default:
				engine.handleEvent(event);
				break;
			}
		}
	}
    return 0;
}

