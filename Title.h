#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

class Title {
public:
	Title(sf::Font titleFont, sf::Font optionsFont, sf::Font arrowFont, sf::Texture* texture);

	std::vector<sf::Text*> getDrawableText() { return drawableText; }
	std::vector<sf::Sprite*> getDrawableSprite() { return drawableSprite; }

	int handleEvent(sf::Event event);

private:
//Graphical components
	sf::Font titleFont;
	sf::Font optionsFont;
	sf::Font arrowFont;

	sf::Text title;
	sf::Text newGame;
	sf::Text loadGame;
	sf::Text arrow;

	sf::Sprite background;

	std::vector<sf::Text*> drawableText;
	std::vector<sf::Sprite*> drawableSprite;

//Members
	int selectedOption = 0;
};