#pragma once
#include "Engine.hpp"
#include "PlayerCharacter.hpp"

enum GameState;

class Menu {
public:
	Menu(sf::Font primaryFont, sf::Font arrowFont, std::vector<PlayerCharacter*> party);

	GameState handleEvent(sf::Event event);
	std::vector<sf::Text*> getDrawableText() { return drawableText; }
	std::vector<sf::Sprite*> getDrawableSprite() { return drawableSprite; }
	std::vector<sf::RectangleShape*> getDrawableShape() { return drawableShape; }

private:
	//Graphical components
	sf::Font JMH_Arkham;
	sf::Font arrowFont;
	
	sf::Text optionResume;
	sf::Text optionInventory;
	sf::Text optionEqupiment;
	sf::Text optionSave;
	sf::Text optionQuit;

	sf::Text partyOneNameAndLevel;
	sf::Text partyOneHP;
	sf::Text partyOneMP;
	sf::Text partyOneXP;
	sf::Text partyOneStr;
	sf::Text partyOneDex;
	sf::Text partyOneWis;

	sf::Text partyTwoNameAndLevel;
	sf::Text partyTwoHP;
	sf::Text partyTwoMP;
	sf::Text partyTwoXP;
	sf::Text partyTwoStr;
	sf::Text partyTwoDex;
	sf::Text partyTwoWis;

	sf::Text partyThreeNameAndLevel;
	sf::Text partyThreeHP;
	sf::Text partyThreeMP;
	sf::Text partyThreeXP;
	sf::Text partyThreeStr;
	sf::Text partyThreeDex;
	sf::Text partyThreeWis;

	sf::Text partyFourNameAndLevel;
	sf::Text partyFourHP;
	sf::Text partyFourMP;
	sf::Text partyFourXP;
	sf::Text partyFourStr;
	sf::Text partyFourDex;
	sf::Text partyFourWis;

	sf::Text arrow;

	sf::Sprite partyOneSprite;
	sf::Sprite partyTwoSprite;
	sf::Sprite partyThreeSprite;
	sf::Sprite partyFourSprite;

	std::vector<sf::Text*> drawableText;
	std::vector<sf::Sprite*> drawableSprite;
	std::vector<sf::RectangleShape*> drawableShape;

//Members
	std::vector<PlayerCharacter*> party;
	int selectedOption = 0;
};