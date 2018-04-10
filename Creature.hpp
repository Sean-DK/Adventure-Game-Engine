#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "Flag.hpp"
#include "Tile.hpp"

class Creature {
public:
	Creature(std::string name, unsigned level, int hitpoints,
		unsigned strength, unsigned exp, std::string biome,
		bool hasFlag, Flag* flag, bool isBoss);

	std::string name;
	unsigned level;
	int hitpoints;
	unsigned strength;
	unsigned exp;
	Biome biome;
	bool hasFlag;
	Flag* flag;
	bool isBoss;

	bool isDead;

	sf::Sprite sprite;
};