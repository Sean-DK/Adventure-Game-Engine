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

	int getCurrentHP() { return currentHP; }
	int getCurrentMP() { return currentMP; }
	int getCurrentXP() { return currentXP; }

	unsigned getStrength() { return strength; }
	unsigned getDexterity() { return dexterity; }
	unsigned getWisdom() { return wisdom; }

	unsigned getTarget() { return target; }
	bool isFleeing() { return flee; }
	bool isDead() { return dead; }

	sf::Sprite* getSprite() { return &sprite; }

//Mutators
	void setTarget(unsigned n);
	void setFleeing(bool b);
	void setDead(bool b);

	void decreaseHP(int n);
	void setXP(int n);

private:
//Stats
	std::string name;

	unsigned level;

	unsigned maxHP;
	unsigned maxMP;
	unsigned maxXP;

	int currentHP;
	int currentMP;
	int currentXP;

	unsigned strength;
	unsigned dexterity;
	unsigned wisdom;

//Combat stuff
	unsigned target;
	bool flee = false;
	bool dead = false;

//Sprites
	sf::Sprite sprite;
};