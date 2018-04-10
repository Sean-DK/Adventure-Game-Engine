#pragma once
#include "PlayerCharacter.hpp"
#include "Creature.hpp"
#include "Engine.hpp"

class Engine;

enum CombatPhase {
	chooseAction,
	chooseTarget,
	evaluateDamage,
	victory,
	defeat,
	flee
};

class Combat {
public:
	Combat(std::vector<PlayerCharacter*> party, std::vector<Creature> creatures, Engine* engine,
		sf::Font primaryFont, sf::Font arrowFont, sf::Font floatingFont, std::vector<sf::Texture*> textures);

	std::vector<sf::Text*> getDrawableText() { return drawableText; }
	std::vector<sf::Sprite*> getDrawableSprite() { return drawableSprite; }
	std::vector<sf::RectangleShape*> getDrawableShape() { return drawableShape; }

	CombatPhase getPhase() { return phase; }

	void handleEvent(sf::Event event);
	void updateStatus();

private:
//Graphical components
	sf::Font JMH_Arkham;
	sf::Font ArcadeClassic;
	sf::Font arrowFont;

	sf::Text creatureOneName;
	sf::Text creatureTwoName;
	sf::Text creatureThreeName;
	sf::Text creatureFourName;
	sf::Text creatureFiveName;
	sf::Text creatureSixName;

	sf::Text partyOneStatus;
	sf::Text partyTwoStatus;
	sf::Text partyThreeStatus;
	sf::Text partyFourStatus;

	sf::Text optionAttack;
	sf::Text optionMagic;
	sf::Text optionItem;
	sf::Text optionFlee;

	sf::RectangleShape statusBackdrop;
	sf::RectangleShape optionsBackdrop;

	sf::Sprite background;

	sf::Sprite creatureOneSprite;
	sf::Sprite creatureTwoSprite;
	sf::Sprite creatureThreeSprite;
	sf::Sprite creatureFourSprite;
	sf::Sprite creatureFiveSprite;
	sf::Sprite creatureSixSprite;

	sf::Sprite partyOneSprite;
	sf::Sprite partyTwoSprite;
	sf::Sprite partyThreeSprite;
	sf::Sprite partyFourSprite;

	sf::Text floatingDamageText;

	sf::Text arrow;

//Members
	std::vector<PlayerCharacter*> party;
	std::vector<Creature> creatures;

	Engine* engine;

	std::vector<sf::Text*> drawableText;
	std::vector<sf::Sprite*> drawableSprite;
	std::vector<sf::RectangleShape*> drawableShape;

	int selectedOption = 0;
	int selectedPlayer = -1; //this must be -1 because when combat starts it tries to select the "next"
							//living player, which would be the player at index 0 assuming he's alive
	int selectedCreature = 0;

	CombatPhase phase = chooseAction;

//Methods

	void handleChooseAction(sf::Event event);
	void handleChooseTarget(sf::Event event);

	void nextPlayer();
	void calculateDamage();
	void selectPlayer(int n);
	void selectCreature(int n);
};