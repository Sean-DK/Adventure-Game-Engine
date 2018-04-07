#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "Flag.hpp"
#include "Tile.hpp"

class Creature {
public:
	Creature(std::string name, unsigned level, unsigned hitpoints,
		unsigned strength, unsigned exp, std::string biome, bool hasFlag, Flag* flag);

	std::string name;
	unsigned level;
	unsigned hitpoints;
	unsigned strength;
	unsigned exp;
	Biome biome;
	bool hasFlag;
	Flag* flag;

	bool isDead;

	sf::Sprite sprite;
};