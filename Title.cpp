#include "stdafx.h"
#include "Title.hpp"

Title::Title(sf::Font titleF, sf::Font optionsF, sf::Font arrowF, sf::Texture* texture) 
	: titleFont(titleF), optionsFont(optionsF), arrowFont(arrowF) {
	title.setString("Adventure Game");
	title.setFont(titleFont);
	title.setCharacterSize(56);
	title.setFillColor(sf::Color::White);
	title.setOutlineColor(sf::Color::Black);
	title.setOutlineThickness(4);
	title.setPosition(sf::Vector2f(25, 25));

	newGame.setString("New");
	newGame.setFont(optionsFont);
	newGame.setCharacterSize(20);
	newGame.setFillColor(sf::Color::White);
	newGame.setOutlineColor(sf::Color::Black);
	newGame.setOutlineThickness(1);
	newGame.setPosition(sf::Vector2f(250, 425));

	loadGame.setString("Load");
	loadGame.setFont(optionsFont);
	loadGame.setCharacterSize(20);
	loadGame.setFillColor(sf::Color(100, 100, 100, 255));
	loadGame.setOutlineColor(sf::Color::Black);
	loadGame.setOutlineThickness(1);
	loadGame.setPosition(sf::Vector2f(250, 475));

	arrow.setString("a");
	arrow.setFont(arrowFont);
	arrow.setCharacterSize(50);
	arrow.setFillColor(sf::Color::White);
	arrow.setOutlineColor(sf::Color::Black);
	arrow.setOutlineThickness(1);
	arrow.setPosition(sf::Vector2f(200, 400));

	background.setTexture(*texture);
	background.setPosition(sf::Vector2f(0, 0));

	drawableText.push_back(&title);
	drawableText.push_back(&newGame);
	drawableText.push_back(&loadGame);
	drawableText.push_back(&arrow);

	drawableSprite.push_back(&background);
}

void Title::setTitle(std::string t) {
	title.setString(t);
}

int Title::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			selectedOption--;
			if (selectedOption < 0) selectedOption = 0;
			arrow.setPosition(sf::Vector2f(200, 400 + (50 * selectedOption)));
			break;
		case sf::Keyboard::Down:
			selectedOption++;
			if (selectedOption > 1) selectedOption = 1;
			arrow.setPosition(sf::Vector2f(200, 400 + (50 * selectedOption)));
			break;
		case sf::Keyboard::Return:
			switch (selectedOption) {
			case 0: return 0;
			case 1: return 1;
			}
		}
	}
	return -1;
}
