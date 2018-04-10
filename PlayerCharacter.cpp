#include "stdafx.h"
#include "PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(std::string name, sf::Texture* texture, int id) 
	: name(name) {
	level = 1;
	maxHP = currentHP = 10;
	maxMP = currentMP = 5;
	maxXP = 10;
	currentXP = 0;
	strength = 1;
	dexterity = 1;
	wisdom = 1;

	//TODO: assign sprite correctly
	sprite.setTexture(*texture);
	switch (id) {
	case 1:
		sprite.setTextureRect(sf::IntRect(160, 192, 46, 64));
		break;
	case 2:
		sprite.setTextureRect(sf::IntRect(114, 192, 46, 64));
		break;
	case 3:
		sprite.setTextureRect(sf::IntRect(68, 192, 46, 64));
		break;
	case 4:
		sprite.setTextureRect(sf::IntRect(207, 192, 46, 64));
		break;
	}
	
}

void PlayerCharacter::setFleeing(bool b) {
	flee = b;
}

void PlayerCharacter::setDead(bool b) {
	dead = b;
}

void PlayerCharacter::decreaseHP(int n) {
	if (currentHP - n < 0) currentHP = 0;
	else currentHP -= n;
}

void PlayerCharacter::setXP(int n) {
	if (n < maxXP) {
		currentXP = n;
	}
	else {
		level++;
		unsigned remainingExperience = n - maxXP;
		maxXP *= 1.2;
		setXP(remainingExperience);
		maxHP += 5;
		currentHP += 5;
		strength += 1;
		dexterity += 1;
		wisdom += 1;
	}
}

void PlayerCharacter::setTarget(unsigned n) {
	target = n;
}
