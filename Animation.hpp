#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "Engine.hpp"

class Engine;

enum AnimationType {
	TitleFadeNew,
	CombatStart,
	CombatEnd,
	GameOverFade,
	PlayerMoveUp,
	PlayerMoveDown,
	PlayerMoveLeft,
	PlayerMoveRight,
	PlayerAttack,
	CreatureAttack,
	ChangeMap,
	VictoryFade,
};

class Animation {
public:
	Animation(AnimationType type, Engine* engine);
	Animation(AnimationType type, int mapID, Engine* engine);
	Animation(AnimationType type, sf::Sprite* mainSprite, Engine* engine);
	Animation(AnimationType type, sf::Sprite* mainSprite, sf::Sprite auxSprite,
		unsigned playerDamage, unsigned creatureDamage, sf::Font* font);

	bool play(sf::Time elapsed);
	AnimationType getType() { return type; }
	sf::RectangleShape getShape() { return shape; }
	sf::Text getFloatingText() { return floatingText; }

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
	double iteration = 0;

	int mapID;

	//CombatDamage data
	unsigned playerDamage;
	unsigned creatureDamage;
	sf::Text floatingText;

//Play functions
	bool playTitleFadeNew(sf::Time elapsed);
	bool playPlayerMoveUp(sf::Time elapsed);
	bool playPlayerMoveDown(sf::Time elapsed);
	bool playPlayerMoveLeft(sf::Time elapsed);
	bool playPlayerMoveRight(sf::Time elapsed);
	bool playChangeMap(sf::Time elapsed);
	bool playCombatStart(sf::Time elapsed);
	bool playCombatEnd(sf::Time elasped);
	bool playPlayerAttack(sf::Time elapsed);
	bool playCreatureAttack(sf::Time elapsed);
	bool playGameOverFade(sf::Time elapsed);
	bool playVictoryFade(sf::Time elapsed);
};