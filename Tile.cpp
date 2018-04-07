#include "stdafx.h"
#include "Tile.hpp"

TileBoss::TileBoss(bool isBoss, Flag* req, unsigned creatureID) 
	: isBoss(isBoss), req(req), creatureID(creatureID) {}

TileLink::TileLink(bool isLink, Flag* req, unsigned mapID)
	: isLink(isLink), req(req), mapID(mapID) {}

Tile::Tile(TileType type, Biome biome, bool solid, unsigned level,
	TileBoss boss, TileLink link, sf::Texture* texture)
	: type(type), biome(biome), solid(solid), level(level), boss(boss), link(link) {
	sprite.setTexture(*texture);
	switch (type) {
	case Empty:
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		break;
	case Plains:
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
		break;
	case Mountain:
		sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
		break;
	case Lake:
		sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
		break;
	case Ocean:
		sprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
		break;
	case City_Floor:
		sprite.setTextureRect(sf::IntRect(160, 0, 32, 32));
		break;
	case City_Wall:
		sprite.setTextureRect(sf::IntRect(192, 0, 32, 32));
		break;
	case Dungeon_Floor:
		sprite.setTextureRect(sf::IntRect(224, 0, 32, 32));
		break;
	case Dungeon_Wall:
		sprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
		break;
	case Cave_Floor:
		sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
		break;
	case Cave_Wall:
		sprite.setTextureRect(sf::IntRect(64, 32, 32, 32));
		break;
	case City_Door:
		sprite.setTextureRect(sf::IntRect(96, 32, 32, 32));
		break;
	case Dungeon_Door:
		sprite.setTextureRect(sf::IntRect(128, 32, 32, 32));
		break;
	case Cave_Door:
		sprite.setTextureRect(sf::IntRect(160, 32, 32, 32));
		break;
	}
}

TileType s2tt(std::string string) {
	if (string == "Empty") return Empty;
	if (string == "Plains") return Plains;
	if (string == "Mountain") return Mountain;
	if (string == "Lake") return Lake;
	if (string == "Ocean") return Ocean;
	if (string == "City_Floor") return City_Floor;
	if (string == "City_Wall") return City_Wall;
	if (string == "Dungeon_Floor") return Dungeon_Floor;
	if (string == "Dungeon_Wall") return Dungeon_Wall;
	if (string == "Cave_Floor") return Cave_Floor;
	if (string == "Cave_Wall") return Cave_Wall;
	if (string == "City_Door") return City_Door;
	if (string == "Dungeon_Door") return Dungeon_Door;
	if (string == "Cave_Door") return Cave_Door;
}

Biome s2b(std::string string)
{
	if (string == "Grassy") return Grassy;
	if (string == "Rocky") return Rocky;
	if (string == "City") return City;
	if (string == "Dungeon") return Dungeon;
	if (string == "Cave") return Cave;
}
