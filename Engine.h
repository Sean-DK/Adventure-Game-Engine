#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

enum GameState {
	Startup,
	Title,
	Overworld,
	CombatStart,
	Combat,
	CombatEnd,
	Menu,
	GameOver
};

class Engine {
public:
	Engine(sf::RenderWindow* window);

private:
//Heap storage for assets
	std::vector<sf::Texture*> textures;
	std::vector<Map*> maps;
	std::vector<Creature*> creatures;
	std::vector<Item*> items;

	/*
	class Flag {
	public:
		Flag()
			: req(nullptr) {}
		Flag(Flag* req)
			: req(req) {}

		bool isComplete() { return val; }
		void complete();
	private:
		bool val;
		Flag* req;
	}

	inline void Flag::complete() {
		if (req->isComplete()) {
			val = true;
		}
		else if (req == nullptr) {
			val == true;
		}
	}
	*/
	std::vector<Flag*> flags;
	Metadata* metadata;

//Load assets
	void loadTextures();
	void loadMaps();
	void loadCreatures();
	void loadItems();
	void loadFlags();

};