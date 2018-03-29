#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <Windows.h>
#include "Engine.h"

int main()
{
	srand(time(NULL));
	FreeConsole();
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Window"/*, sf::Style::None*/);
	Engine engine(window);

	sf::Clock clock;
	while (window->isOpen()) {
		sf::Time elapsed = clock.restart();
		engine.updateGame(elapsed);

		sf::Event event;
		while (window->pollEvent(event)) {
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

