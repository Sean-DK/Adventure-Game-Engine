#include "stdafx.h"
#include "Combat.hpp"

Combat::Combat(std::vector<PlayerCharacter*> p, std::vector<Creature> c, Engine* e, 
	sf::Font primaryFont, sf::Font arrowF, sf::Font floatingFont)
	: party(p), creatures(c), engine(e), JMH_Arkham(primaryFont), 
	arrowFont(arrowF), ArcadeClassic(floatingFont) {
	//Set creature names
	for (unsigned i = 0; i < creatures.size(); i++) {
		switch (i) {
		case 0:
			creatureOneName.setString(creatures[0].name);
			creatureOneName.setFont(JMH_Arkham);
			creatureOneName.setCharacterSize(22);
			creatureOneName.setFillColor(sf::Color::White);
			creatureOneName.setOutlineColor(sf::Color::Black);
			creatureOneName.setOutlineThickness(1);

			drawableText.push_back(&creatureOneName);
			
			creatureOneSprite = creatures[0].sprite;

			drawableSprite.push_back(&creatureOneSprite);
			break;
		case 1:
			creatureTwoName.setString(creatures[1].name);
			creatureTwoName.setFont(JMH_Arkham);
			creatureTwoName.setCharacterSize(22);
			creatureTwoName.setFillColor(sf::Color::White);
			creatureTwoName.setOutlineColor(sf::Color::Black);
			creatureTwoName.setOutlineThickness(1);

			drawableText.push_back(&creatureTwoName);

			creatureTwoSprite = creatures[1].sprite;

			drawableSprite.push_back(&creatureTwoSprite);
			break;
		case 2:
			creatureThreeName.setString(creatures[2].name);
			creatureThreeName.setFont(JMH_Arkham);
			creatureThreeName.setCharacterSize(22);
			creatureThreeName.setFillColor(sf::Color::White);
			creatureThreeName.setOutlineColor(sf::Color::Black);
			creatureThreeName.setOutlineThickness(1);

			drawableText.push_back(&creatureThreeName);

			creatureThreeSprite = creatures[2].sprite;

			drawableSprite.push_back(&creatureThreeSprite);
			break;
		case 3:
			creatureFourName.setString(creatures[3].name);
			creatureFourName.setFont(JMH_Arkham);
			creatureFourName.setCharacterSize(22);
			creatureFourName.setFillColor(sf::Color::White);
			creatureFourName.setOutlineColor(sf::Color::Black);
			creatureFourName.setOutlineThickness(1);

			drawableText.push_back(&creatureFourName);

			creatureFourSprite = creatures[3].sprite;

			drawableSprite.push_back(&creatureFourSprite);
			break;
		case 4:
			creatureFiveName.setString(creatures[4].name);
			creatureFiveName.setFont(JMH_Arkham);
			creatureFiveName.setCharacterSize(22);
			creatureFiveName.setFillColor(sf::Color::White);
			creatureFiveName.setOutlineColor(sf::Color::Black);
			creatureFiveName.setOutlineThickness(1);

			drawableText.push_back(&creatureFiveName);

			creatureFiveSprite = creatures[4].sprite;
			
			drawableSprite.push_back(&creatureFiveSprite);
			break;
		case 5:
			creatureSixName.setString(creatures[5].name);
			creatureSixName.setFont(JMH_Arkham);
			creatureSixName.setCharacterSize(22);
			creatureSixName.setFillColor(sf::Color::White);
			creatureSixName.setOutlineColor(sf::Color::Black);
			creatureSixName.setOutlineThickness(1);

			drawableText.push_back(&creatureSixName);

			creatureSixSprite = creatures[5].sprite;

			drawableSprite.push_back(&creatureSixSprite);
			break;
		}
	}
	
	//Set player status text
	std::string str = "";
	str += party[0]->getName();
	str += " HP ";
	str += std::to_string(party[0]->getCurrentHP());
	str += "/";
	str += std::to_string(party[0]->getMaxHP());
	str += " MP ";
	str += std::to_string(party[0]->getCurrentMP());
	str += "/";
	str += std::to_string(party[0]->getMaxMP());
	partyOneStatus.setString(str);
	partyOneStatus.setFont(JMH_Arkham);
	partyOneStatus.setCharacterSize(22);
	partyOneStatus.setFillColor(sf::Color::White);
	partyOneStatus.setOutlineColor(sf::Color::Black);
	partyOneStatus.setOutlineThickness(1);

	drawableText.push_back(&partyOneStatus);

	partyOneSprite = *party[0]->getSprite();
	
	drawableSprite.push_back(&partyOneSprite);
	str.clear();

	str += party[1]->getName();
	str += " HP ";
	str += std::to_string(party[1]->getCurrentHP());
	str += "/";
	str += std::to_string(party[1]->getMaxHP());
	str += " MP ";
	str += std::to_string(party[1]->getCurrentMP());
	str += "/";
	str += std::to_string(party[1]->getMaxMP());
	partyTwoStatus.setString(str);
	partyTwoStatus.setFont(JMH_Arkham);
	partyTwoStatus.setCharacterSize(22);
	partyTwoStatus.setFillColor(sf::Color::White);
	partyTwoStatus.setOutlineColor(sf::Color::Black);
	partyTwoStatus.setOutlineThickness(1);

	drawableText.push_back(&partyTwoStatus);

	partyTwoSprite = *party[1]->getSprite();
	
	drawableSprite.push_back(&partyTwoSprite);
	str.clear();

	str += party[2]->getName();
	str += " HP ";
	str += std::to_string(party[2]->getCurrentHP());
	str += "/";
	str += std::to_string(party[2]->getMaxHP());
	str += " MP ";
	str += std::to_string(party[2]->getCurrentMP());
	str += "/";
	str += std::to_string(party[2]->getMaxMP());
	partyThreeStatus.setString(str);
	partyThreeStatus.setFont(JMH_Arkham);
	partyThreeStatus.setCharacterSize(22);
	partyThreeStatus.setFillColor(sf::Color::White);
	partyThreeStatus.setOutlineColor(sf::Color::Black);
	partyThreeStatus.setOutlineThickness(1);
	
	drawableText.push_back(&partyThreeStatus);

	partyThreeSprite = *party[2]->getSprite();
	
	drawableSprite.push_back(&partyThreeSprite);
	str.clear();

	str += party[3]->getName();
	str += " HP ";
	str += std::to_string(party[3]->getCurrentHP());
	str += "/";
	str += std::to_string(party[3]->getMaxHP());
	str += " MP ";
	str += std::to_string(party[3]->getCurrentMP());
	str += "/";
	str += std::to_string(party[3]->getMaxMP());
	partyFourStatus.setString(str);
	partyFourStatus.setFont(JMH_Arkham);
	partyFourStatus.setCharacterSize(22);
	partyFourStatus.setFillColor(sf::Color::White);
	partyFourStatus.setOutlineColor(sf::Color::Black);
	partyFourStatus.setOutlineThickness(1);
	
	drawableText.push_back(&partyFourStatus);

	partyFourSprite = *party[3]->getSprite();

	drawableSprite.push_back(&partyFourSprite);
	str.clear();

	optionAttack.setString("Attack");
	optionAttack.setFont(JMH_Arkham);
	optionAttack.setCharacterSize(22);
	optionAttack.setFillColor(sf::Color::White);
	optionAttack.setOutlineColor(sf::Color::Black);
	optionAttack.setOutlineThickness(1);

	drawableText.push_back(&optionAttack);

	optionMagic.setString("Magic");
	optionMagic.setFont(JMH_Arkham);
	optionMagic.setCharacterSize(22);
	optionMagic.setFillColor(sf::Color::White);
	optionMagic.setOutlineColor(sf::Color::Black);
	optionMagic.setOutlineThickness(1);

	drawableText.push_back(&optionMagic);

	optionItem.setString("Item");
	optionItem.setFont(JMH_Arkham);
	optionItem.setCharacterSize(22);
	optionItem.setFillColor(sf::Color::White);
	optionItem.setOutlineColor(sf::Color::Black);
	optionItem.setOutlineThickness(1);

	drawableText.push_back(&optionItem);

	optionFlee.setString("Flee");
	optionFlee.setFont(JMH_Arkham);
	optionFlee.setCharacterSize(22);
	optionFlee.setFillColor(sf::Color::White);
	optionFlee.setOutlineColor(sf::Color::Black);
	optionFlee.setOutlineThickness(1);

	drawableText.push_back(&optionFlee);

	floatingDamageText.setCharacterSize(22);
	floatingDamageText.setFillColor(sf::Color::White);
	floatingDamageText.setOutlineColor(sf::Color::Black);
	floatingDamageText.setOutlineThickness(1);

	drawableText.push_back(&floatingDamageText);

	statusBackdrop.setSize(sf::Vector2f(800, 200));
	statusBackdrop.setPosition(sf::Vector2f(0, 400));
	statusBackdrop.setFillColor(sf::Color::Blue);
	statusBackdrop.setOutlineColor(sf::Color::White);
	statusBackdrop.setOutlineThickness(-2);

	drawableShape.push_back(&statusBackdrop);

	optionsBackdrop.setSize(sf::Vector2f(125, 400));
	optionsBackdrop.setPosition(sf::Vector2f(300, 400));
	optionsBackdrop.setFillColor(sf::Color::Blue);
	optionsBackdrop.setOutlineColor(sf::Color::White);
	optionsBackdrop.setOutlineThickness(-2);

	drawableShape.push_back(&optionsBackdrop);
}
