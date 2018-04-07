#pragma once
#include "Tile.hpp"
#include "Engine.hpp"

class Engine;
enum GameState;


class Map {
public:
	Map(std::string path, sf::Texture* texture, std::vector<Flag*> flags, Engine* engine);

	std::vector<sf::Sprite*> getDrawableSprite() { return drawableSprite; }

	GameState handleEvent(sf::Event event);

private:
	Engine* engine;

	unsigned gridWidth;
	unsigned playerPreviousPosition;
	unsigned playerCurrentPosition;
	unsigned movesSinceLastBattle = 0;
	std::vector<Tile> grid;
	sf::Sprite playerSprite;
	sf::Texture* texture;
	std::vector<Flag*> flags;

	std::vector<sf::Sprite*> drawableSprite;

	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();

	bool randomBattle();
};