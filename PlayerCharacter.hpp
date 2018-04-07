#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

class PlayerCharacter {
public:
	PlayerCharacter(std::string name, sf::Texture* texture, int id);

//Accessors
	std::string getName() { return name; }
	
	unsigned getLevel() { return level; }

	unsigned getMaxHP() { return maxHP; }
	unsigned getMaxMP() { return maxMP; }
	unsigned getMaxXP() { return maxXP; }

	unsigned getCurrentHP() { return currentHP; }
	unsigned getCurrentMP() { return currentMP; }
	unsigned getCurrentXP() { return currentXP; }

	unsigned getStrength() { return strength; }
	unsigned getDexterity() { return dexterity; }
	unsigned getWisdom() { return wisdom; }

	bool isFleeing() { return flee; }
	bool isDead() { return dead; }

	sf::Sprite* getSprite() { return &sprite; }

private:
//Stats
	std::string name;

	unsigned level;

	unsigned maxHP;
	unsigned maxMP;
	unsigned maxXP;

	unsigned currentHP;
	unsigned currentMP;
	unsigned currentXP;

	unsigned strength;
	unsigned dexterity;
	unsigned wisdom;

//Combat stuff
	//Creature* target;
	bool flee = false;
	bool dead = false;

//Sprites
	sf::Sprite sprite;
};