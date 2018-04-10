#include "stdafx.h"
#include "Animation.hpp"

//TitleFade & CombatStart
Animation::Animation(AnimationType type, Engine * engine)
	: type(type), engine(engine) {
	switch (type) {
	case TitleFadeNew: {
		sf::Color color = sf::Color::Black;
		r = color.r;
		g = color.g;
		b = color.b;
		a = 0;
		
		initialDuration = duration = 500;
		changePerMillisecond = 255 / duration;

		shape.setSize(sf::Vector2f(800, 600));
		shape.setPosition(sf::Vector2f(0, 0));
		shape.setFillColor(sf::Color(r, g, b, a));
		break;
	}
	case CombatStart: {
		sf::Color color = sf::Color::White;
		r = color.r;
		g = color.g;
		b = color.b;
		a = 0;

		initialDuration = duration = 200;
		changePerMillisecond = 255 / duration;

		shape.setSize(sf::Vector2f(2336, 2136));
		shape.setPosition(sf::Vector2f(-400, -300));
		shape.setFillColor(sf::Color(r, g, b, a));
		break;
	}
	case CombatEnd: {
		sf::Color color = sf::Color::White;
		r = color.r;
		g = color.g;
		b = color.b;
		a = 0;

		initialDuration = duration = 200;
		changePerMillisecond = 255 / duration;

		shape.setSize(sf::Vector2f(800, 600));
		shape.setPosition(sf::Vector2f(0, 0));
		shape.setFillColor(sf::Color(r, g, b, a));
		break;
	}
	case GameOverFade: {
		sf::Color color = sf::Color::Black;
		r = color.r;
		g = color.g;
		b = color.b;
		a = 0;

		duration = 1000;
		changePerMillisecond = 255 / duration;

		shape.setSize(sf::Vector2f(800, 600));
		shape.setPosition(sf::Vector2f(0, 0));
		shape.setFillColor(sf::Color(r, g, b, a));

		sf::Font* font = new sf::Font();
		font->loadFromFile("Fonts\\JMH Arkham.ttf");
		floatingText.setFont(*font);
		floatingText.setFillColor(sf::Color(255, 0, 0, 0));
		floatingText.setCharacterSize(36);
		floatingText.setPosition(300, 250);
		floatingText.setString("Game Over");
		break;
	}
	case VictoryFade: {
		sf::Color color = sf::Color::Black;
		r = color.r;
		g = color.g;
		b = color.b;
		a = 0;

		initialDuration = duration = 500;
		changePerMillisecond = 255 / duration;

		shape.setSize(sf::Vector2f(800, 600));
		shape.setPosition(sf::Vector2f(0, 0));
		shape.setFillColor(sf::Color(r, g, b, a));

		sf::Font* font = new sf::Font();
		font->loadFromFile("Fonts\\JMH Arkham.ttf");
		floatingText.setFont(*font);
		floatingText.setFillColor(sf::Color(0, 255, 0, 0));
		floatingText.setCharacterSize(36);
		floatingText.setPosition(320, 250);
		floatingText.setString("Victory!");
		break;
	}
	}
}

//ChangeMap
Animation::Animation(AnimationType type, int mapID, Engine* engine) 
	: type(type), mapID(mapID), engine(engine) {
	sf::Color color = sf::Color::Black;
	r = color.r;
	g = color.g;
	b = color.b;
	a = 0;

	initialDuration = duration = 500;
	changePerMillisecond = 255 / duration;

	shape.setSize(sf::Vector2f(2336, 2136));
	shape.setPosition(sf::Vector2f(-400, -300));
	shape.setFillColor(sf::Color(r, g, b, a));
}

//PlayerMove
Animation::Animation(AnimationType type, sf::Sprite* mainSprite, Engine* engine) 
	: type(type), mainSprite(mainSprite), engine(engine) {
	switch (type) {
	case PlayerMoveUp: 
	case PlayerMoveDown: 
	case PlayerMoveLeft:
	case PlayerMoveRight: {
		duration = 300;
		a = mainSprite->getPosition().x;
		b = mainSprite->getPosition().y;
		changePerMillisecond = 32 / duration;
	}
	}
}

//CreatureAttack & PlayerAttack
Animation::Animation(AnimationType type, sf::Sprite* mainSprite, sf::Sprite auxSprite,
	unsigned playerDamage, unsigned creatureDamage, sf::Font* font) 
	: type(type), mainSprite(mainSprite), auxSprite(auxSprite), playerDamage(playerDamage),
	creatureDamage(creatureDamage) {
	duration = initialDuration = 200;
	a = mainSprite->getPosition().x;
	b = mainSprite->getPosition().y;
	floatingText.setFont(*font);
	floatingText.setCharacterSize(22);
	floatingText.setFillColor(sf::Color::White);
	floatingText.setOutlineColor(sf::Color::Black);
	floatingText.setOutlineThickness(1);
	floatingText.setPosition(auxSprite.getPosition().x + 40, auxSprite.getPosition().y);
	switch (type) {
	case PlayerAttack:
		changePerMillisecond = -0.25;
		if (!playerDamage) floatingText.setString("Miss!");
		else floatingText.setString(std::to_string(playerDamage));
		break;
	case CreatureAttack:
		changePerMillisecond = 0.25;
		if (!creatureDamage) floatingText.setString("Miss!");
		else floatingText.setString(std::to_string(creatureDamage));
		break;
	}
}

bool Animation::play(sf::Time elapsed) {
	switch (type) {
	case TitleFadeNew: return playTitleFadeNew(elapsed);
	case PlayerMoveUp: return playPlayerMoveUp(elapsed);
	case PlayerMoveDown: return playPlayerMoveDown(elapsed);
	case PlayerMoveLeft: return playPlayerMoveLeft(elapsed);
	case PlayerMoveRight: return playPlayerMoveRight(elapsed);
	case ChangeMap: return playChangeMap(elapsed);
	case CombatStart: return playCombatStart(elapsed);
	case CombatEnd: return playCombatEnd(elapsed);
	case PlayerAttack: return playPlayerAttack(elapsed);
	case CreatureAttack: return playCreatureAttack(elapsed);
	case GameOverFade: return playGameOverFade(elapsed);
	case VictoryFade: return playVictoryFade(elapsed);
	}
}

bool Animation::playTitleFadeNew(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration -= elapsed;
		if (duration == 0) {
			engine->changeState(_Overworld);
			reverse = true;
		}
	}
	else {
		if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
		double delta = changePerMillisecond * elapsed;
		a -= delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration += elapsed;
		if (duration == initialDuration) {
			return true;
		}
	}
	return false;
}

bool Animation::playPlayerMoveUp(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	b -= delta;
	mainSprite->setPosition(sf::Vector2f(a, b));
	duration -= elapsed;
	if (duration == 0) {
		return true;
	}
	return false;
}

bool Animation::playPlayerMoveDown(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	b += delta;
	mainSprite->setPosition(sf::Vector2f(a, b));
	duration -= elapsed;
	if (duration == 0) {
		return true;
	}
	return false;
}

bool Animation::playPlayerMoveLeft(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	a -= delta;
	mainSprite->setPosition(sf::Vector2f(a, b));
	duration -= elapsed;
	if (duration == 0) {
		return true;
	}
	return false;
}

bool Animation::playPlayerMoveRight(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	a += delta;
	mainSprite->setPosition(sf::Vector2f(a, b));
	duration -= elapsed;
	if (duration == 0) {
		return true;
	}
	return false;
}

bool Animation::playChangeMap(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration -= elapsed;
		if (duration == 0) {
			engine->changeCurrentMap(mapID);
			reverse = true;
		}
	}
	else {
		if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
		double delta = changePerMillisecond * elapsed;
		a -= delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration += elapsed;
		if (duration == initialDuration) {
			return true;
		}
	}
	return false;
}

bool Animation::playCombatStart(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (iteration == -1) return true;
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration -= elapsed;
		if (duration == 0) {
			if (iteration == 2) {
				engine->changeState(_Combat);
				initialDuration = 500;
				changePerMillisecond = 255 / initialDuration;
			}
			reverse = true;
		}
	}
	else {
		if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
		double delta = changePerMillisecond * elapsed;
		a -= delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration += elapsed;
		if (duration == initialDuration) {
			if (iteration == 2) iteration = -1;
			else {
				iteration++;
				reverse = false;
			}
		}
	}
	return false;
}

bool Animation::playCombatEnd(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration -= elapsed;
		if (duration == 0) {
			engine->changeState(_Overworld);
			reverse = true;
		}
	}
	else {
		if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
		double delta = changePerMillisecond * elapsed;
		a -= delta;
		shape.setFillColor(sf::Color(r, g, b, a));
		duration += elapsed;
		if (duration == initialDuration) {
			return true;
		}
	}
	return false;
}

bool Animation::playPlayerAttack(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		mainSprite->setPosition(sf::Vector2f(a, b));
		duration -= elapsed;
		if (duration == 0) {
			reverse = true;
		}
	}
	else {
		if (iteration < 200) iteration += elapsed;
		else {
			if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
			double delta = changePerMillisecond * elapsed;
			a -= delta;
			mainSprite->setPosition(sf::Vector2f(a, b));
			duration += elapsed;
			if (duration == initialDuration) {
				return true;
			}
		}
	}
	double m = floatingText.getPosition().x;
	double n = floatingText.getPosition().y - (0.1 * elapsed);
	floatingText.setPosition(m, n);
	return false;
}

bool Animation::playCreatureAttack(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (!reverse) {
		if (duration - elapsed < 0) elapsed = duration;
		double delta = changePerMillisecond * elapsed;
		a += delta;
		mainSprite->setPosition(sf::Vector2f(a, b));
		duration -= elapsed;
		if (duration == 0) {
			reverse = true;
		}
	}
	else {
		if (iteration < 200) iteration += elapsed;
		else {
			if (duration + elapsed > initialDuration) elapsed = initialDuration - duration;
			double delta = changePerMillisecond * elapsed;
			a -= delta;
			mainSprite->setPosition(sf::Vector2f(a, b));
			duration += elapsed;
			if (duration == initialDuration) {
				return true;
			}
		}
	}
	double m = floatingText.getPosition().x;
	double n = floatingText.getPosition().y - (0.1 * elapsed);
	floatingText.setPosition(m, n);
	return false;
}

bool Animation::playGameOverFade(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	a += delta;
	shape.setFillColor(sf::Color(r, g, b, a));
	floatingText.setFillColor(sf::Color(255, 0, 0, a));
	duration -= elapsed;
	if (duration == 0) {
		return false;
	}
	return false;
}

bool Animation::playVictoryFade(sf::Time e) {
	double elapsed = e.asMilliseconds();
	if (duration - elapsed < 0) elapsed = duration;
	double delta = changePerMillisecond * elapsed;
	a += delta;
	shape.setFillColor(sf::Color(r, g, b, a));
	floatingText.setFillColor(sf::Color(0, 255, 0, a));
	duration -= elapsed;
	if (duration == 0) {
		return false;
	}
	return false;
}
