#include "stdafx.h"
#include "Map.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Map::Map(std::string path, sf::Texture* texture, std::vector<Flag*> flags, Engine* engine)
	: texture(texture), flags(flags), engine(engine) {
	std::ifstream file;
	file.open(path);
	if (file.is_open()) {
		json j;
		file >> j;
		
		//Read the spawn location of the map
		playerCurrentPosition = playerPreviousPosition = j.at("Spawn").get<unsigned>();

		//Read the width of the grid
		gridWidth = j.at("Width").get<unsigned>();

		//Read and reserve the total size of grid
		unsigned totalTiles = j.at("Tiles").get<unsigned>();
		grid.reserve(totalTiles);

		//Read and store each tile in grid
		for (unsigned i = 0; i < totalTiles; i++) {
			std::string tileNumber = std::to_string(i);
			std::string typeStr, biomeStr;
			bool solid, isBoss, isLink;
			unsigned level, bossReq, bossID, linkReq, linkID;
			typeStr = j.at(tileNumber).at("TileType").get<std::string>();
			biomeStr = j.at(tileNumber).at("Biome").get<std::string>();
			solid = j.at(tileNumber).at("Solid").get<bool>();
			level = j.at(tileNumber).at("Level").get<unsigned>();
			isBoss = j.at(tileNumber).at("Boss").at("isBoss").get<bool>();
			bossReq = j.at(tileNumber).at("Boss").at("FlagReq").get<unsigned>();
			bossID = j.at(tileNumber).at("Boss").at("CreatureID").get<unsigned>();
			isLink = j.at(tileNumber).at("Link").at("isLink").get<bool>();
			linkReq = j.at(tileNumber).at("Link").at("FlagReq").get<unsigned>();
			linkID = j.at(tileNumber).at("Link").at("MapID").get<unsigned>();

			TileBoss tileBoss(isBoss, flags[bossReq], bossID);
			TileLink tileLink(isLink, flags[linkReq], linkID);

			TileType type = s2tt(typeStr);
			Biome biome = s2b(biomeStr);

			grid.push_back(Tile(type, biome, solid, level, tileBoss, tileLink, texture));
		}
	}
	playerSprite.setTexture(*texture);
	playerSprite.setTextureRect(sf::IntRect(0, 224, 32, 32));
	playerSprite.setPosition(sf::Vector2f((playerCurrentPosition % gridWidth) * 32, (playerCurrentPosition / gridWidth) * 32));
	for (unsigned i = 0; i < grid.size(); i++) {
		sf::Sprite* sprite = grid[i].getSprite();
		sprite->setPosition(sf::Vector2f((i % gridWidth) * 32, (i / gridWidth) * 32));
		drawableSprite.push_back(grid[i].getSprite());
	}
	drawableSprite.push_back(&playerSprite);
}

GameState Map::handleEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			if (moveUp()) return _CombatStart;
			break;
		case sf::Keyboard::Down:
			if (moveDown()) return _CombatStart;
			break;
		case sf::Keyboard::Left:
			if (moveLeft()) return _CombatStart;
			break;
		case sf::Keyboard::Right:
			if (moveRight()) return _CombatStart;
			break;
		case sf::Keyboard::Return:
			return _Menu;
			break;
		}
	}
	return _Overworld;
}

bool Map::moveUp() {
	unsigned newPosition = playerCurrentPosition - gridWidth;
	if (newPosition < grid.size()) {
		Tile newTile = grid[newPosition];
		if (!newTile.isSolid()) {
			if (!newTile.getTileLink().isLink) {
				bool battleResult = randomBattle();
				playerPreviousPosition = playerCurrentPosition;
				playerCurrentPosition -= gridWidth;
				engine->startAnimation(Animation(PlayerMoveUp, &playerSprite, engine));
				if (battleResult) {
					return true;
				}
			}
			else {
				if (newTile.getTileLink().req->isComplete()) {
					engine->startAnimation(Animation(ChangeMap, newTile.getTileLink().mapID, engine));
				}
			}
		}
	}
	return false;
}

bool Map::moveDown() {
	unsigned newPosition = playerCurrentPosition + gridWidth;
	if (newPosition < grid.size()) {
		Tile newTile = grid[newPosition];
		if (!newTile.isSolid()) {
			if (!newTile.getTileLink().isLink) {
				bool battleResult = randomBattle();
				playerPreviousPosition = playerCurrentPosition;
				playerCurrentPosition += gridWidth;
				engine->startAnimation(Animation(PlayerMoveDown, &playerSprite, engine));
				if (battleResult) {
					return true;
				}
			}
			else {
				if (newTile.getTileLink().req->isComplete()) {
					engine->startAnimation(Animation(ChangeMap, newTile.getTileLink().mapID, engine));
				}
			}
		}
	}
	return false;
}

bool Map::moveLeft() {
	unsigned newPosition = playerCurrentPosition - 1;
	if (newPosition < grid.size()) {
		Tile newTile = grid[newPosition];
		if (newPosition % gridWidth == gridWidth - 1) {}
		else if (!newTile.isSolid()) {
			if (!newTile.getTileLink().isLink) {
				bool battleResult = randomBattle();
				playerPreviousPosition = playerCurrentPosition;
				playerCurrentPosition -= 1;
				engine->startAnimation(Animation(PlayerMoveLeft, &playerSprite, engine));
				if (battleResult) {
					return true;
				}
			}
			else {
				if (newTile.getTileLink().req->isComplete()) {
					engine->startAnimation(Animation(ChangeMap, newTile.getTileLink().mapID, engine));
				}
			}
		}
	}
	return false;
}

bool Map::moveRight() {
	unsigned newPosition = playerCurrentPosition + 1;
	if (newPosition < grid.size()) {
		Tile newTile = grid[newPosition];
		if (newPosition % gridWidth == 0) {}
		else if (!newTile.isSolid()) {
			if (!newTile.getTileLink().isLink) {
				bool battleResult = randomBattle();
				playerPreviousPosition = playerCurrentPosition;
				playerCurrentPosition += 1;
				engine->startAnimation(Animation(PlayerMoveRight, &playerSprite, engine));
				if (battleResult) {
					return true;
				}
			}
			else {
				if (newTile.getTileLink().req->isComplete()) {
					engine->startAnimation(Animation(ChangeMap, newTile.getTileLink().mapID, engine));
				}
			}
		}
	}
	return false;
}

bool Map::randomBattle() {
	unsigned baseChance = 20;
	unsigned actualChance = baseChance - movesSinceLastBattle;
	if (rand() % actualChance == 0) {
		movesSinceLastBattle = 0;
		return true;
	}
	movesSinceLastBattle++;
	return false;
}
