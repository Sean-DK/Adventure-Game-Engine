#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <Windows.h>

int main()
{
	srand(time(NULL));
	FreeConsole();
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Window"/*, sf::Style::None*/);

	sf::Clock clock;
	while (window->isOpen()) {
		sf::Time elapsed = clock.restart();
		//updateGame(elapsed);

		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			default:
				//handleEvent(event);
				break;
			}
		}
		window->clear();
		//window.draw();
		window->display();
	}
    return 0;
}

