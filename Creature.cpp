#include "stdafx.h"
#include "Creature.hpp"

Creature::Creature(std::string n, unsigned l, unsigned h, 
	unsigned s, unsigned e, std::string b, bool hF, Flag* f)
	: name(n), level(l), hitpoints(h), strength(s), exp(e), 
	hasFlag(hF), flag(f) {
	biome = s2b(b);

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Textures\\1 - spriteTextureSheet.png");
	sprite.setTexture(*texture);
	if (name == "Goblin") {
		sprite.setTextureRect(sf::IntRect(0, 64, 41, 64));
	}
	if (name == "Cave Goblin") {
		sprite.setTextureRect(sf::IntRect(41, 64, 41, 64));
	}
	if (name == "Goblin Chief") {
		sprite.setTextureRect(sf::IntRect(82, 64, 41, 64));
	}
	if (name == "Bat") {
		sprite.setTextureRect(sf::IntRect(192, 32, 64, 64));
	}
	else {
		sprite.setTextureRect(sf::IntRect(0, 64, 41, 64));
	}
}
