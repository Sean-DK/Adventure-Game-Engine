#include "stdafx.h"
#include "Menu.hpp"

Menu::Menu(sf::Font primaryFont, sf::Font arrowF, std::vector<PlayerCharacter*> party)
	: JMH_Arkham(primaryFont), arrowFont(arrowF), party(party) {
	optionResume.setString("Resume");
	optionResume.setPosition(sf::Vector2f(40, 20));

	optionInventory.setString("Inventory");
	optionInventory.setPosition(sf::Vector2f(40, 40));

	optionEqupiment.setString("Equipment");
	optionEqupiment.setPosition(sf::Vector2f(40, 60));

	optionSave.setString("Save");
	optionSave.setPosition(sf::Vector2f(40, 80));

	optionQuit.setString("Quit");
	optionQuit.setPosition(sf::Vector2f(40, 100));

	partyOneNameAndLevel.setString(party[0]->getName() + " Lv. " + std::to_string(party[0]->getLevel()));
	partyOneNameAndLevel.setPosition(sf::Vector2f(300, 50));
	partyOneHP.setString("HP: " + std::to_string(party[0]->getCurrentHP()) + "/" + std::to_string(party[0]->getMaxHP()));
	partyOneHP.setPosition(sf::Vector2f(300, 70));
	partyOneMP.setString("MP: " + std::to_string(party[0]->getCurrentMP()) + "/" + std::to_string(party[0]->getMaxMP()));
	partyOneMP.setPosition(sf::Vector2f(300, 90));
	partyOneXP.setString("XP: " + std::to_string(party[0]->getCurrentXP()) + "/" + std::to_string(party[0]->getMaxXP()));
	partyOneXP.setPosition(sf::Vector2f(300, 110));
	partyOneStr.setString("STR: " + std::to_string(party[0]->getStrength()));
	partyOneStr.setPosition(sf::Vector2f(450, 70));
	partyOneDex.setString("DEX: " + std::to_string(party[0]->getDexterity()));
	partyOneDex.setPosition(sf::Vector2f(450, 90));
	partyOneWis.setString("WIS: " + std::to_string(party[0]->getWisdom()));
	partyOneWis.setPosition(sf::Vector2f(450, 110));

	partyTwoNameAndLevel.setString(party[1]->getName() + " Lv. " + std::to_string(party[1]->getLevel()));
	partyTwoNameAndLevel.setPosition(sf::Vector2f(300, 180));
	partyTwoHP.setString("HP: " + std::to_string(party[1]->getCurrentHP()) + "/" + std::to_string(party[1]->getMaxHP()));
	partyTwoHP.setPosition(sf::Vector2f(300, 200));
	partyTwoMP.setString("MP: " + std::to_string(party[1]->getCurrentMP()) + "/" + std::to_string(party[1]->getMaxMP()));
	partyTwoMP.setPosition(sf::Vector2f(300, 220));
	partyTwoXP.setString("XP: " + std::to_string(party[1]->getCurrentXP()) + "/" + std::to_string(party[1]->getMaxXP()));
	partyTwoXP.setPosition(sf::Vector2f(300, 240));
	partyTwoStr.setString("STR: " + std::to_string(party[1]->getStrength()));
	partyTwoStr.setPosition(sf::Vector2f(450, 200));
	partyTwoDex.setString("DEX: " + std::to_string(party[1]->getDexterity()));
	partyTwoDex.setPosition(sf::Vector2f(450, 220));
	partyTwoWis.setString("WIS: " + std::to_string(party[1]->getWisdom()));
	partyTwoWis.setPosition(sf::Vector2f(450, 240));

	partyThreeNameAndLevel.setString(party[2]->getName() + " Lv. " + std::to_string(party[2]->getLevel()));
	partyThreeNameAndLevel.setPosition(sf::Vector2f(300, 310));
	partyThreeHP.setString("HP: " + std::to_string(party[2]->getCurrentHP()) + "/" + std::to_string(party[2]->getMaxHP()));
	partyThreeHP.setPosition(sf::Vector2f(300, 330));
	partyThreeMP.setString("MP: " + std::to_string(party[2]->getCurrentMP()) + "/" + std::to_string(party[2]->getMaxMP()));
	partyThreeMP.setPosition(sf::Vector2f(300, 350));
	partyThreeXP.setString("XP: " + std::to_string(party[2]->getCurrentXP()) + "/" + std::to_string(party[2]->getMaxXP()));
	partyThreeXP.setPosition(sf::Vector2f(300, 370));
	partyThreeStr.setString("STR: " + std::to_string(party[2]->getStrength()));
	partyThreeStr.setPosition(sf::Vector2f(450, 330));
	partyThreeDex.setString("DEX: " + std::to_string(party[2]->getDexterity()));
	partyThreeDex.setPosition(sf::Vector2f(450, 350));
	partyThreeWis.setString("WIS: " + std::to_string(party[2]->getWisdom()));
	partyThreeWis.setPosition(sf::Vector2f(450, 370));

	partyFourNameAndLevel.setString(party[3]->getName() + " Lv. " + std::to_string(party[3]->getLevel()));
	partyFourNameAndLevel.setPosition(sf::Vector2f(300, 440));
	partyFourHP.setString("HP: " + std::to_string(party[3]->getCurrentHP()) + "/" + std::to_string(party[3]->getMaxHP()));
	partyFourHP.setPosition(sf::Vector2f(300, 460));
	partyFourMP.setString("MP: " + std::to_string(party[3]->getCurrentMP()) + "/" + std::to_string(party[3]->getMaxMP()));
	partyFourMP.setPosition(sf::Vector2f(300, 480));
	partyFourXP.setString("XP: " + std::to_string(party[3]->getCurrentXP()) + "/" + std::to_string(party[3]->getMaxXP()));
	partyFourXP.setPosition(sf::Vector2f(300, 500));
	partyFourStr.setString("STR: " + std::to_string(party[3]->getStrength()));
	partyFourStr.setPosition(sf::Vector2f(450, 460));
	partyFourDex.setString("DEX: " + std::to_string(party[3]->getDexterity()));
	partyFourDex.setPosition(sf::Vector2f(450, 480));
	partyFourWis.setString("WIS: " + std::to_string(party[3]->getWisdom()));
	partyFourWis.setPosition(sf::Vector2f(450, 500));

	drawableText.push_back(&optionResume);
	drawableText.push_back(&optionInventory);
	drawableText.push_back(&optionEqupiment);
	drawableText.push_back(&optionSave);
	drawableText.push_back(&optionQuit);

	drawableText.push_back(&partyOneNameAndLevel);
	drawableText.push_back(&partyOneHP);
	drawableText.push_back(&partyOneMP);
	drawableText.push_back(&partyOneXP);
	drawableText.push_back(&partyOneStr);
	drawableText.push_back(&partyOneDex);
	drawableText.push_back(&partyOneWis);

	drawableText.push_back(&partyTwoNameAndLevel);
	drawableText.push_back(&partyTwoHP);
	drawableText.push_back(&partyTwoMP);
	drawableText.push_back(&partyTwoXP);
	drawableText.push_back(&partyTwoStr);
	drawableText.push_back(&partyTwoDex);
	drawableText.push_back(&partyTwoWis);

	drawableText.push_back(&partyThreeNameAndLevel);
	drawableText.push_back(&partyThreeHP);
	drawableText.push_back(&partyThreeMP);
	drawableText.push_back(&partyThreeXP);
	drawableText.push_back(&partyThreeStr);
	drawableText.push_back(&partyThreeDex);
	drawableText.push_back(&partyThreeWis);

	drawableText.push_back(&partyFourNameAndLevel);
	drawableText.push_back(&partyFourHP);
	drawableText.push_back(&partyFourMP);
	drawableText.push_back(&partyFourXP);
	drawableText.push_back(&partyFourStr);
	drawableText.push_back(&partyFourDex);
	drawableText.push_back(&partyFourWis);

	for (unsigned i = 0; i < drawableText.size(); i++) {
		drawableText[i]->setFont(JMH_Arkham);
		drawableText[i]->setCharacterSize(16);
		drawableText[i]->setFillColor(sf::Color::White);
		drawableText[i]->setOutlineColor(sf::Color::Black);
		drawableText[i]->setOutlineThickness(1);
		//Disable inventory/equipment
		if (i == 1 || i == 2) {
			drawableText[i]->setFillColor(sf::Color(100, 100, 100, 255));
		}
	}

	arrow.setFont(arrowFont);
	arrow.setString("a");
	arrow.setCharacterSize(24);
	arrow.setFillColor(sf::Color::White);
	arrow.setOutlineColor(sf::Color::Black);
	arrow.setOutlineThickness(1);
	arrow.setPosition(sf::Vector2f(20, 15));
	drawableText.push_back(&arrow);

	drawableShape.push_back(new sf::RectangleShape(sf::Vector2f(150, 115)));
	drawableShape[0]->setPosition(sf::Vector2f(15, 15));
	drawableShape[0]->setFillColor(sf::Color::Blue);
	drawableShape[0]->setOutlineColor(sf::Color::White);
	drawableShape[0]->setOutlineThickness(-2);
	drawableShape.push_back(new sf::RectangleShape(sf::Vector2f(150, 445)));
	drawableShape[1]->setPosition(sf::Vector2f(15, 140));
	drawableShape[1]->setFillColor(sf::Color::Blue);
	drawableShape[1]->setOutlineColor(sf::Color::White);
	drawableShape[1]->setOutlineThickness(-2);
	drawableShape.push_back(new sf::RectangleShape(sf::Vector2f(610, 570)));
	drawableShape[2]->setPosition(sf::Vector2f(175, 15));
	drawableShape[2]->setFillColor(sf::Color::Blue);
	drawableShape[2]->setOutlineColor(sf::Color::White);
	drawableShape[2]->setOutlineThickness(-2);

	partyOneSprite = *party[0]->getSprite();
	partyOneSprite.setPosition(220, 60);
	partyTwoSprite = *party[1]->getSprite();
	partyTwoSprite.setPosition(220, 190);
	partyThreeSprite = *party[2]->getSprite();
	partyThreeSprite.setPosition(220, 320);
	partyFourSprite = *party[3]->getSprite();
	partyFourSprite.setPosition(220, 450);

	drawableSprite.push_back(&partyOneSprite);
	drawableSprite.push_back(&partyTwoSprite);
	drawableSprite.push_back(&partyThreeSprite);
	drawableSprite.push_back(&partyFourSprite);
}

GameState Menu::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			selectedOption--;
			if (selectedOption < 0) selectedOption = 4;
			arrow.setPosition(sf::Vector2f(20, 15 + (20 * selectedOption)));
			break;
		case sf::Keyboard::Down:
			selectedOption++;
			if (selectedOption > 4) selectedOption = 0;
			arrow.setPosition(sf::Vector2f(20, 15 + (20 * selectedOption)));
			break;
		case sf::Keyboard::Return:
			switch (selectedOption) {
			case 0: return _Overworld;
			case 3: //TODO: Save
				break;
			case 4: return _Quit;
			}
		}
	}
	return _Menu;
}
