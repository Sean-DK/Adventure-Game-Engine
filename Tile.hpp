#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "Flag.hpp"

enum TileType {
	Empty,
	Plains,
	Mountain,
	Lake,
	Ocean,
	City_Floor,
	City_Wall,
	Dungeon_Floor,
	Dungeon_Wall,
	Cave_Floor,
	Cave_Wall,
	City_Door,
	Dungeon_Door,
	Cave_Door
};

enum Biome {
	Grassy,
	Rocky,
	City,
	Dungeon,
	Cave
};

class TileBoss {
public:
	TileBoss(bool isBoss, Flag* req, unsigned creatureID);

	bool isBoss;
	Flag* req;
	unsigned creatureID;
};

class TileLink {
public:
	TileLink(bool isLink, Flag* req, unsigned mapID);

	bool isLink;
	Flag* req;
	unsigned mapID;
};

class Tile {
public:
	Tile(TileType type, Biome biome, bool solid, unsigned level,
		TileBoss boss, TileLink link, sf::Texture* texture);

	TileType getType() { return type; }
	Biome getBiome() { return biome; }
	bool isSolid() { return solid; }
	unsigned getLevel() { return level; }
	TileBoss getTileBoss() { return boss; }
	TileLink getTileLink() { return link; }
	sf::Sprite* getSprite() { return &sprite; }

private:
	TileType type;
	Biome biome;
	bool solid;
	unsigned level;
	TileBoss boss;
	TileLink link;
	sf::Sprite sprite;
};

TileType s2tt(std::string string);
Biome s2b(std::string string);