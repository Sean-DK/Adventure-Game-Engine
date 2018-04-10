#include "stdafx.h"
#include "Combat.hpp"

Combat::Combat(std::vector<PlayerCharacter*> p, std::vector<Creature> c, Engine* e, 
	sf::Font primaryFont, sf::Font arrowF, sf::Font floatingFont, std::vector<sf::Texture*> textures)
	: party(p), creatures(c), engine(e), JMH_Arkham(primaryFont), 
	arrowFont(arrowF), ArcadeClassic(floatingFont) {
	//Set background
	switch (creatures[0].biome) {
	case Grassy:
		background.setTexture(*textures[2]);
		break;
	case Rocky:
		background.setTexture(*textures[5]);
		break;
	case City:
	case Dungeon:
		background.setTexture(*textures[4]);
		break;
	case Cave:
		background.setTexture(*textures[3]);
		break;
	}
	drawableSprite.push_back(&background);

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
			creatureOneName.setPosition(sf::Vector2f(75, 410));

			drawableText.push_back(&creatureOneName);
			
			creatureOneSprite = creatures[0].sprite;
			creatureOneSprite.setPosition(sf::Vector2f(250, 150));

			drawableSprite.push_back(&creatureOneSprite);
			break;
		case 1:
			creatureTwoName.setString(creatures[1].name);
			creatureTwoName.setFont(JMH_Arkham);
			creatureTwoName.setCharacterSize(22);
			creatureTwoName.setFillColor(sf::Color::White);
			creatureTwoName.setOutlineColor(sf::Color::Black);
			creatureTwoName.setOutlineThickness(1);
			creatureTwoName.setPosition(sf::Vector2f(75, 438));

			drawableText.push_back(&creatureTwoName);

			creatureTwoSprite = creatures[1].sprite;
			creatureTwoSprite.setPosition(sf::Vector2f(250, 230));

			drawableSprite.push_back(&creatureTwoSprite);
			break;
		case 2:
			creatureThreeName.setString(creatures[2].name);
			creatureThreeName.setFont(JMH_Arkham);
			creatureThreeName.setCharacterSize(22);
			creatureThreeName.setFillColor(sf::Color::White);
			creatureThreeName.setOutlineColor(sf::Color::Black);
			creatureThreeName.setOutlineThickness(1);
			creatureThreeName.setPosition(sf::Vector2f(75, 466));

			drawableText.push_back(&creatureThreeName);

			creatureThreeSprite = creatures[2].sprite;
			creatureThreeSprite.setPosition(sf::Vector2f(250, 310));

			drawableSprite.push_back(&creatureThreeSprite);
			break;
		case 3:
			creatureFourName.setString(creatures[3].name);
			creatureFourName.setFont(JMH_Arkham);
			creatureFourName.setCharacterSize(22);
			creatureFourName.setFillColor(sf::Color::White);
			creatureFourName.setOutlineColor(sf::Color::Black);
			creatureFourName.setOutlineThickness(1);
			creatureFourName.setPosition(sf::Vector2f(75, 494));

			drawableText.push_back(&creatureFourName);

			creatureFourSprite = creatures[3].sprite;
			creatureFourSprite.setPosition(sf::Vector2f(100, 150));

			drawableSprite.push_back(&creatureFourSprite);
			break;
		case 4:
			creatureFiveName.setString(creatures[4].name);
			creatureFiveName.setFont(JMH_Arkham);
			creatureFiveName.setCharacterSize(22);
			creatureFiveName.setFillColor(sf::Color::White);
			creatureFiveName.setOutlineColor(sf::Color::Black);
			creatureFiveName.setOutlineThickness(1);
			creatureFiveName.setPosition(sf::Vector2f(75, 522));

			drawableText.push_back(&creatureFiveName);

			creatureFiveSprite = creatures[4].sprite;
			creatureFiveSprite.setPosition(sf::Vector2f(100, 230));
			
			drawableSprite.push_back(&creatureFiveSprite);
			break;
		case 5:
			creatureSixName.setString(creatures[5].name);
			creatureSixName.setFont(JMH_Arkham);
			creatureSixName.setCharacterSize(22);
			creatureSixName.setFillColor(sf::Color::White);
			creatureSixName.setOutlineColor(sf::Color::Black);
			creatureSixName.setOutlineThickness(1);
			creatureSixName.setPosition(sf::Vector2f(75, 550));

			drawableText.push_back(&creatureSixName);

			creatureSixSprite = creatures[5].sprite;
			creatureSixSprite.setPosition(sf::Vector2f(100, 310));

			drawableSprite.push_back(&creatureSixSprite);
			break;
		}
	}
	
	//Set player status text
	std::string str = "";
	str += party[0]->getName();
	str += "  HP ";
	str += std::to_string(party[0]->getCurrentHP());
	str += "/";
	str += std::to_string(party[0]->getMaxHP());
	str += "    MP ";
	str += std::to_string(party[0]->getCurrentMP());
	str += "/";
	str += std::to_string(party[0]->getMaxMP());
	partyOneStatus.setString(str);
	partyOneStatus.setFont(JMH_Arkham);
	partyOneStatus.setCharacterSize(22);
	partyOneStatus.setFillColor(sf::Color::White);
	partyOneStatus.setOutlineColor(sf::Color::Black);
	partyOneStatus.setOutlineThickness(1);
	partyOneStatus.setPosition(sf::Vector2f(430, 410));

	drawableText.push_back(&partyOneStatus);

	partyOneSprite = *party[0]->getSprite();
	partyOneSprite.setPosition(sf::Vector2f(600, 150));
	
	drawableSprite.push_back(&partyOneSprite);
	str.clear();

	str += party[1]->getName();
	str += "  HP ";
	str += std::to_string(party[1]->getCurrentHP());
	str += "/";
	str += std::to_string(party[1]->getMaxHP());
	str += "    MP ";
	str += std::to_string(party[1]->getCurrentMP());
	str += "/";
	str += std::to_string(party[1]->getMaxMP());
	partyTwoStatus.setString(str);
	partyTwoStatus.setFont(JMH_Arkham);
	partyTwoStatus.setCharacterSize(22);
	partyTwoStatus.setFillColor(sf::Color::White);
	partyTwoStatus.setOutlineColor(sf::Color::Black);
	partyTwoStatus.setOutlineThickness(1);
	partyTwoStatus.setPosition(sf::Vector2f(430, 438));

	drawableText.push_back(&partyTwoStatus);

	partyTwoSprite = *party[1]->getSprite();
	partyTwoSprite.setPosition(sf::Vector2f(600, 200));
	
	drawableSprite.push_back(&partyTwoSprite);
	str.clear();

	str += party[2]->getName();
	str += "   HP ";
	str += std::to_string(party[2]->getCurrentHP());
	str += "/";
	str += std::to_string(party[2]->getMaxHP());
	str += "    MP ";
	str += std::to_string(party[2]->getCurrentMP());
	str += "/";
	str += std::to_string(party[2]->getMaxMP());
	partyThreeStatus.setString(str);
	partyThreeStatus.setFont(JMH_Arkham);
	partyThreeStatus.setCharacterSize(22);
	partyThreeStatus.setFillColor(sf::Color::White);
	partyThreeStatus.setOutlineColor(sf::Color::Black);
	partyThreeStatus.setOutlineThickness(1);
	partyThreeStatus.setPosition(sf::Vector2f(430, 466));
	
	drawableText.push_back(&partyThreeStatus);

	partyThreeSprite = *party[2]->getSprite();
	partyThreeSprite.setPosition(sf::Vector2f(600, 250));
	
	drawableSprite.push_back(&partyThreeSprite);
	str.clear();

	str += party[3]->getName();
	str += "   HP ";
	str += std::to_string(party[3]->getCurrentHP());
	str += "/";
	str += std::to_string(party[3]->getMaxHP());
	str += "    MP ";
	str += std::to_string(party[3]->getCurrentMP());
	str += "/";
	str += std::to_string(party[3]->getMaxMP());
	partyFourStatus.setString(str);
	partyFourStatus.setFont(JMH_Arkham);
	partyFourStatus.setCharacterSize(22);
	partyFourStatus.setFillColor(sf::Color::White);
	partyFourStatus.setOutlineColor(sf::Color::Black);
	partyFourStatus.setOutlineThickness(1);
	partyFourStatus.setPosition(sf::Vector2f(430, 494));
	
	drawableText.push_back(&partyFourStatus);

	partyFourSprite = *party[3]->getSprite();
	partyFourSprite.setPosition(sf::Vector2f(600, 300));

	drawableSprite.push_back(&partyFourSprite);
	str.clear();

	optionAttack.setString("Attack");
	optionAttack.setFont(JMH_Arkham);
	optionAttack.setCharacterSize(22);
	optionAttack.setFillColor(sf::Color::White);
	optionAttack.setOutlineColor(sf::Color::Black);
	optionAttack.setOutlineThickness(1);
	optionAttack.setPosition(sf::Vector2f(340, 410));

	drawableText.push_back(&optionAttack);

	optionMagic.setString("Magic");
	optionMagic.setFont(JMH_Arkham);
	optionMagic.setCharacterSize(22);
	optionMagic.setFillColor(sf::Color(100, 100, 100, 255)); //disabled color
	optionMagic.setOutlineColor(sf::Color::Black);
	optionMagic.setOutlineThickness(1);
	optionMagic.setPosition(sf::Vector2f(340, 438));

	drawableText.push_back(&optionMagic);

	optionItem.setString("Item");
	optionItem.setFont(JMH_Arkham);
	optionItem.setCharacterSize(22);
	optionItem.setFillColor(sf::Color(100, 100, 100, 255)); //disabled color
	optionItem.setOutlineColor(sf::Color::Black);
	optionItem.setOutlineThickness(1);
	optionItem.setPosition(sf::Vector2f(340, 466));

	drawableText.push_back(&optionItem);

	optionFlee.setString("Flee");
	optionFlee.setFont(JMH_Arkham);
	optionFlee.setCharacterSize(22);
	optionFlee.setFillColor(sf::Color::White);
	optionFlee.setOutlineColor(sf::Color::Black);
	optionFlee.setOutlineThickness(1);
	optionFlee.setPosition(sf::Vector2f(340, 494));

	drawableText.push_back(&optionFlee);

	statusBackdrop.setSize(sf::Vector2f(800, 200));
	statusBackdrop.setPosition(sf::Vector2f(0, 400));
	statusBackdrop.setFillColor(sf::Color::Blue);
	statusBackdrop.setOutlineColor(sf::Color::White);
	statusBackdrop.setOutlineThickness(-2);

	drawableShape.push_back(&statusBackdrop);

	optionsBackdrop.setSize(sf::Vector2f(125, 200));
	optionsBackdrop.setPosition(sf::Vector2f(300, 400));
	optionsBackdrop.setFillColor(sf::Color::Blue);
	optionsBackdrop.setOutlineColor(sf::Color::White);
	optionsBackdrop.setOutlineThickness(-2);

	drawableShape.push_back(&optionsBackdrop);

	arrow.setFont(arrowFont);
	arrow.setString("a");
	arrow.setCharacterSize(32);
	arrow.setFillColor(sf::Color::White);
	arrow.setOutlineColor(sf::Color::Black);
	arrow.setOutlineThickness(1);
	arrow.setPosition(sf::Vector2f(310, 404));

	drawableText.push_back(&arrow);

	floatingDamageText.setCharacterSize(22);
	floatingDamageText.setFillColor(sf::Color::White);
	floatingDamageText.setOutlineColor(sf::Color::Black);
	floatingDamageText.setOutlineThickness(1);

	drawableText.push_back(&floatingDamageText);

	nextPlayer();
}

void Combat::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (phase) {
		case chooseAction:
			handleChooseAction(event);
			break;
		case chooseTarget:
			handleChooseTarget(event);
			break;
		case evaluateDamage:
		case victory:
		case defeat:
		case flee:
			//ignore input
			break;
		}
	}
}

void Combat::handleChooseAction(sf::Event event) {
	switch (event.key.code) {
	case sf::Keyboard::Up:
		selectedOption--;
		if (selectedOption < 0) selectedOption = 3;
		arrow.setPosition(310, 404 + (selectedOption * 28));
		break;
	case sf::Keyboard::Down:
		selectedOption++;
		if (selectedOption > 3) selectedOption = 0;
		arrow.setPosition(310, 404 + (selectedOption * 28));
		break;
	case sf::Keyboard::Return:
		switch (selectedOption) {
		case 0:
			phase = chooseTarget;
			selectCreature(selectedCreature);
			selectPlayer(-1); //sets all party text to white
			party[selectedPlayer]->setFleeing(false);
		case 1:
		case 2:
			//magic/item
			break;
		case 3:
			party[selectedPlayer]->setFleeing(true);
			nextPlayer();
		}
	}
}

void Combat::handleChooseTarget(sf::Event event) {
	switch (event.key.code) {
	case sf::Keyboard::Up:
		selectedCreature--;
		if (selectedCreature < 0) selectedCreature = creatures.size() - 1;
		while (creatures[selectedCreature].isDead) {
			if (--selectedCreature < 0) selectedCreature = creatures.size() - 1;
		}
		selectCreature(selectedCreature);
		break;
	case sf::Keyboard::Down:
		selectedCreature++;
		if (selectedCreature >= creatures.size()) selectedCreature = 0;
		while (creatures[selectedCreature].isDead) {
			if (++selectedCreature > creatures.size() - 1) selectedCreature = 0;
		}
		selectCreature(selectedCreature);
		break;
	case sf::Keyboard::Return:
		party[selectedPlayer]->setTarget(selectedCreature);
		nextPlayer();
		break;
	}
}

void Combat::nextPlayer() {
	while (1) {
		if (++selectedPlayer < party.size()) {
			if (!party[selectedPlayer]->isDead()) {
				phase = chooseAction;
				break;
			}
		}
		else {
			phase = evaluateDamage;
			calculateDamage();
			break;
		}
	}
	selectPlayer(selectedPlayer);
	selectCreature(-1); //sets all creature text to white
}

void Combat::calculateDamage() {
	//Calculate damage creatures will deal and store in vector
	//Also determine which player will be attacked
	std::vector<unsigned> creatureDamage;
	std::vector<unsigned> creatureTarget;
	for (unsigned i = 0; i < creatures.size(); i++) {
		creatureDamage.push_back(creatures[i].strength);
		unsigned target = rand() % 4;
		while (party[target]->isDead()) {
			target = rand() % 4;
		}
		creatureTarget.push_back(target);
	}
	//Calculate damage players will deal and store in vector
	std::vector<unsigned> playerDamage;
	for (unsigned i = 0; i < party.size(); i++) {
		playerDamage.push_back(party[i]->getStrength());
	}
	//Evaluate damage and display animation
	std::vector<sf::Sprite*> partySprites;
	for (unsigned i = 0; i < party.size(); i++) {
		partySprites.push_back(drawableSprite[i + creatures.size() + 1]);
	}
	std::vector<sf::Sprite*> creatureSprites;
	for (unsigned i = 0; i < creatures.size(); i++) {
		creatureSprites.push_back(drawableSprite[i + 1]);
	}
	//Evaluate combat damage
	//Creature attack animations
	for (unsigned i = 0; i < creatures.size(); i++) {
		if (!creatures[i].isDead) {
			engine->startAnimation(Animation(CreatureAttack, creatureSprites[i], *partySprites[creatureTarget[i]],
				0, creatureDamage[i], &ArcadeClassic));
			party[creatureTarget[i]]->decreaseHP(creatureDamage[i]);
		}
	}
	//Player attack animations
	for (unsigned i = 0; i < party.size(); i++) {
		if (!party[i]->isDead() && !party[i]->isFleeing()) {
			engine->startAnimation(Animation(PlayerAttack, partySprites[i], *creatureSprites[party[i]->getTarget()],
				playerDamage[i], 0, &ArcadeClassic));
			creatures[party[i]->getTarget()].hitpoints -= playerDamage[i];
		}
	}
	updateStatus();
}

void Combat::selectPlayer(int n) {
	partyOneStatus.setFillColor(sf::Color::White);
	partyTwoStatus.setFillColor(sf::Color::White);
	partyThreeStatus.setFillColor(sf::Color::White);
	partyFourStatus.setFillColor(sf::Color::White);
	switch (n) {
	case 0:
		partyOneStatus.setFillColor(sf::Color::Yellow);
		break;
	case 1:
		partyTwoStatus.setFillColor(sf::Color::Yellow);
		break;
	case 2:
		partyThreeStatus.setFillColor(sf::Color::Yellow);
		break;
	case 3:
		partyFourStatus.setFillColor(sf::Color::Yellow);
		break;
	default:
		//none;
		break;
	}
}

void Combat::selectCreature(int n) {
	for (unsigned i = 0; i < creatures.size(); i++) {
		if (i == 0) creatureOneName.setFillColor(sf::Color::White);
		if (i == 1) creatureTwoName.setFillColor(sf::Color::White);
		if (i == 2) creatureThreeName.setFillColor(sf::Color::White);
		if (i == 3) creatureFourName.setFillColor(sf::Color::White);
		if (i == 4) creatureFiveName.setFillColor(sf::Color::White);
		if (i == 5) creatureSixName.setFillColor(sf::Color::White);
	}
	switch (n) {
	case 0:
		creatureOneName.setFillColor(sf::Color::Yellow);
		break;
	case 1:
		creatureTwoName.setFillColor(sf::Color::Yellow);
		break;
	case 2:
		creatureThreeName.setFillColor(sf::Color::Yellow);
		break;
	case 3:
		creatureFourName.setFillColor(sf::Color::Yellow);
		break;
	case 4:
		creatureFiveName.setFillColor(sf::Color::Yellow);
		break;
	case 5:
		creatureSixName.setFillColor(sf::Color::Yellow);
		break;
	default:
		//none
		break;
	}
}

void Combat::updateStatus() {
	if (!engine->isAnimating()) {
		std::string str = "";
		str += party[0]->getName();
		str += "  HP ";
		str += std::to_string(party[0]->getCurrentHP());
		str += "/";
		str += std::to_string(party[0]->getMaxHP());
		str += "    MP ";
		str += std::to_string(party[0]->getCurrentMP());
		str += "/";
		str += std::to_string(party[0]->getMaxMP());
		partyOneStatus.setString(str);
		partyOneStatus.setFont(JMH_Arkham);
		partyOneStatus.setCharacterSize(22);
		partyOneStatus.setFillColor(sf::Color::White);
		partyOneStatus.setOutlineColor(sf::Color::Black);
		partyOneStatus.setOutlineThickness(1);
		partyOneStatus.setPosition(sf::Vector2f(430, 410));

		str.clear();

		str += party[1]->getName();
		str += "  HP ";
		str += std::to_string(party[1]->getCurrentHP());
		str += "/";
		str += std::to_string(party[1]->getMaxHP());
		str += "    MP ";
		str += std::to_string(party[1]->getCurrentMP());
		str += "/";
		str += std::to_string(party[1]->getMaxMP());
		partyTwoStatus.setString(str);
		partyTwoStatus.setFont(JMH_Arkham);
		partyTwoStatus.setCharacterSize(22);
		partyTwoStatus.setFillColor(sf::Color::White);
		partyTwoStatus.setOutlineColor(sf::Color::Black);
		partyTwoStatus.setOutlineThickness(1);
		partyTwoStatus.setPosition(sf::Vector2f(430, 438));

		str.clear();

		str += party[2]->getName();
		str += "   HP ";
		str += std::to_string(party[2]->getCurrentHP());
		str += "/";
		str += std::to_string(party[2]->getMaxHP());
		str += "    MP ";
		str += std::to_string(party[2]->getCurrentMP());
		str += "/";
		str += std::to_string(party[2]->getMaxMP());
		partyThreeStatus.setString(str);
		partyThreeStatus.setFont(JMH_Arkham);
		partyThreeStatus.setCharacterSize(22);
		partyThreeStatus.setFillColor(sf::Color::White);
		partyThreeStatus.setOutlineColor(sf::Color::Black);
		partyThreeStatus.setOutlineThickness(1);
		partyThreeStatus.setPosition(sf::Vector2f(430, 466));

		str.clear();

		str += party[3]->getName();
		str += "   HP ";
		str += std::to_string(party[3]->getCurrentHP());
		str += "/";
		str += std::to_string(party[3]->getMaxHP());
		str += "    MP ";
		str += std::to_string(party[3]->getCurrentMP());
		str += "/";
		str += std::to_string(party[3]->getMaxMP());
		partyFourStatus.setString(str);
		partyFourStatus.setFont(JMH_Arkham);
		partyFourStatus.setCharacterSize(22);
		partyFourStatus.setFillColor(sf::Color::White);
		partyFourStatus.setOutlineColor(sf::Color::Black);
		partyFourStatus.setOutlineThickness(1);
		partyFourStatus.setPosition(sf::Vector2f(430, 494));

		//Check for player deaths
		for (unsigned i = 0; i < party.size(); i++) {
			if (party[i]->getCurrentHP() <= 0) party[i]->setDead(true);
		}
		//Check for creature deaths
		for (unsigned i = 0; i < creatures.size(); i++) {
			if (creatures[i].hitpoints <= 0) {
				creatures[i].isDead = true;
				drawableSprite[i + 1]->setScale(0, 0);
				drawableText[i]->setString("");
			}
		}
		//Check for combat end state
		bool alive = false;
		for (unsigned i = 0; i < party.size(); i++) {
			if (!party[i]->isDead()) alive = true;
		}
		if (!alive) phase = defeat;
		else {
			alive = false;
			for (unsigned i = 0; i < creatures.size(); i++) {
				if (!creatures[i].isDead) alive = true;
			}
			if (!alive) phase = victory;
		}
		//Check for fleeing
		bool flee = true;
		for (unsigned i = 0; i < party.size(); i++) {
			if (!party[i]->isFleeing()) flee = false;
		}
		if (flee) engine->changeState(_Overworld);
		//Determine control flow
		switch (phase) {
		case victory: {
			int exp = 0;
			for (unsigned i = 0; i < creatures.size(); i++) {
				exp += creatures[i].exp;
				if (creatures[i].hasFlag) {
					creatures[i].flag->complete();
					engine->checkFlags();
				}
			}
			for (unsigned i = 0; i < party.size(); i++) {
				if (!party[i]->isDead()) party[i]->setXP(party[i]->getCurrentXP() + exp);
			}
			engine->startAnimation(Animation(CombatEnd, engine));
			engine->changeState(_CombatEnd);
			break;
		}
		case defeat:
			engine->startAnimation(Animation(GameOverFade, engine));
			break;
		default:
			phase = chooseAction;
			selectedOption = 0;
			arrow.setPosition(310, 404 + (selectedOption * 28));

			selectedPlayer = -1;
			
			selectedCreature = -1;
			while (creatures[++selectedCreature].isDead
				&&selectedCreature < creatures.size());

			nextPlayer();
			break;
		}
	}
}