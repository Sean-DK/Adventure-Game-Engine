#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "Engine.hpp"

class Engine;

enum AnimationType {
	TitleFadeNew,
	CombatStart,
	GameOverFade,
	PlayerMoveUp,
	PlayerMoveDown,
	PlayerMoveLeft,
	PlayerMoveRight,
	PlayerAttack,
	CreatureAttack,
	ChangeMap,
};

class Animation {
public:
	Animation(AnimationType type, Engine* engine);
	Animation(AnimationType type, int mapID, Engine* engine);
	Animation(AnimationType type, sf::Sprite* mainSprite, Engine* engine);

	bool play(sf::Time elapsed);
	AnimationType getType() { return type; }
	sf::RectangleShape getShape() { return shape; }

private:
	double r, g, b, a;
	double changePerMillisecond;
	double duration;
	double initialDuration;

	sf::Sprite* mainSprite;
	sf::Sprite auxSprite;

	sf::RectangleShape shape;

	Engine* engine;
	AnimationType type;

	bool reverse = false;
	int iteration = 0;

	int mapID;

//Play functions
	bool playTitleFadeNew(sf::Time elapsed);
	bool playPlayerMoveUp(sf::Time elapsed);
	bool playPlayerMoveDown(sf::Time elapsed);
	bool playPlayerMoveLeft(sf::Time elapsed);
	bool playPlayerMoveRight(sf::Time elapsed);
	bool playChangeMap(sf::Time elapsed);
	bool playCombatStart(sf::Time elapsed);
};