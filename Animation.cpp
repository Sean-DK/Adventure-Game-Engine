#include "stdafx.h"
#include "Animation.hpp"

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

bool Animation::play(sf::Time elapsed) {
	switch (type) {
	case TitleFadeNew: return playTitleFadeNew(elapsed);
	case PlayerMoveUp: return playPlayerMoveUp(elapsed);
	case PlayerMoveDown: return playPlayerMoveDown(elapsed);
	case PlayerMoveLeft: return playPlayerMoveLeft(elapsed);
	case PlayerMoveRight: return playPlayerMoveRight(elapsed);
	case ChangeMap: return playChangeMap(elapsed);
	case CombatStart: return playCombatStart(elapsed);
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
