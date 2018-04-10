#include "stdafx.h"
#include "Engine.hpp"
#include "Dirent.hpp"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

void Engine::startup() {
	/*Pre-startup consists of loading the fonts necessary for the
	startup screen to be drawn, as well as creating the rectangle shapes
	that are used as the loading bar.*/
	loadFonts();
	contentName.setFillColor(sf::Color::White);
	contentName.setCharacterSize(28);
	contentName.setFont(Cambria);
	contentName.setPosition(sf::Vector2f(300, 210));
	contentName.setString("Performing startup");

	percentComplete.setFillColor(sf::Color::White);
	percentComplete.setCharacterSize(28);
	percentComplete.setFont(Cambria);
	double tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	percentComplete.setString("");

	loadingBarBorder.setSize(sf::Vector2f(400, 50));
	loadingBarBorder.setFillColor(sf::Color::Transparent);
	loadingBarBorder.setOutlineColor(sf::Color::Red);
	loadingBarBorder.setOutlineThickness(2.0f);
	loadingBarBorder.setPosition(sf::Vector2f(200, 250));

	loadingBarFill.setSize(sf::Vector2f(1, 50));
	loadingBarFill.setFillColor(sf::Color::Red);
	loadingBarFill.setPosition(sf::Vector2f(200, 250));

	draw();
	/*Count all the files that must be loaded in order to create a benchmark
	for the percent of loading completed*/
	countFiles();
	
	/*Load the game's metadata*/
	contentName.setString("Loading metadata - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	percentComplete.setString("0%");
	loadingBarFill.setSize(sf::Vector2f(1, 50));
	draw();

	loadMetadata();
	
	/*Load textures, textures must be loaded before maps, items, and creatures because
	textures are used in each of those*/
	contentName.setString("Loading textures - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	unsigned tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();

	loadTextures();

	/*Load flags, flags must be loaded before maps, items, and creatues because the loading
	process of each of those requires access to flags*/
	contentName.setString("Loading flags - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();

	loadFlags();

	/*Load maps*/
	contentName.setString("Loading maps - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();
	
	loadMaps();

	/*Load creatures*/
	contentName.setString("Loading creatures - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();
	
	loadCreatures();

	/*Load items*/
	contentName.setString("Loading items - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();
	
	loadItems();

	/*Cleanup display*/
	contentName.setString("Finishing up - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();

	createTitle();
	createParty();
	createMenu();

	sf::Clock tempClock;
	while (tempClock.getElapsedTime().asMilliseconds() < 300) {}
	changeState(_Title);
}

void Engine::countFiles() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Metadata")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Fonts")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Textures")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Maps")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Creatures")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Items")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	if ((dir = opendir("Flags")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	totalFiles = files.size();
}

void Engine::draw() {
	window->clear();
	switch (currentState) {
	case _Startup:
		drawStartup();
		break;
	case _Title:
		drawTitle();
		break;
	case _Overworld:
		drawOverworld();
		break;
	case _CombatStart:
		drawCombatStart();
		break;
	case _Combat:
		drawCombat();
		break;
	case _CombatEnd:
		drawCombatEnd();
		break;
	case _Menu:
		drawMenu();
		break;
	case _GameOver:
		drawGameOver();
		break;
	case _Quit:
		drawQuit();
		break;
	}
	if (!animations.empty()) drawAnimation();
	window->display();
}

void Engine::updateAnimations(sf::Time elapsed) {
	if (!animations.empty())
		if (animations[0].play(elapsed)) 
			animations.erase(animations.begin());
}

void Engine::combatStart() {
	std::vector<Creature> enemies;
	//generate number of enemies
	double numCreaturesChance = double(rand()) / RAND_MAX;
	unsigned numCreatures;
	if (numCreaturesChance <= 0.2) numCreatures = 1;
	if (numCreaturesChance > 0.2 && numCreaturesChance <= 0.45) numCreatures = 2;
	if (numCreaturesChance > 0.45 && numCreaturesChance <= 0.75) numCreatures = 3;
	if (numCreaturesChance > 0.75 && numCreaturesChance <= 0.85) numCreatures = 4;
	if (numCreaturesChance > 0.85 && numCreaturesChance <= 0.95) numCreatures = 5;
	if (numCreaturesChance > 0.95) numCreatures = 6;
	//generate type of enemies
	for (unsigned i = 0; i < numCreatures; i++) {
		int id = rand() % creatures.size();
		if (creatures[id]->biome == currentMap->getCurrentTileBiome()
			&& !creatures[id]->isBoss) {
			enemies.push_back(*creatures[id]);
		}
		else {
			while (creatures[id]->biome != currentMap->getCurrentTileBiome()
				|| creatures[id]->isBoss) {
				id = rand() % creatures.size();
				if (creatures[id]->biome == currentMap->getCurrentTileBiome()
					&& !creatures[id]->isBoss) {
					enemies.push_back(*creatures[id]);
				}
			}
		}
	}
	combatEnvironment = new Combat(party, enemies, this, JMH_Arkham, Arrows, ArcadeClassic, textures);
	startAnimation(Animation(CombatStart, this));
}

void Engine::bossCombatStart(unsigned bossID) {
	std::vector<Creature> boss;
	boss.push_back(*creatures[bossID]);
	combatEnvironment = new Combat(party, boss, this, JMH_Arkham, Arrows, ArcadeClassic, textures);
	startAnimation(Animation(CombatStart, this));
}

void Engine::startAnimation(Animation animation) {
	animations.push_back(animation);
}

void Engine::changeCurrentMap(unsigned id) {
	currentMap = maps[id];
	currentMapID = id;
}

void Engine::checkFlags() {
	bool complete = true;
	for (unsigned i = 0; i < flags.size(); i++) {
		if (!flags[i]->isComplete()) complete = false;
	}
	if (complete) {
		startAnimation(Animation(VictoryFade, this));
	}
}

void Engine::changeState(GameState state) {
	currentState = state;
}

void Engine::drawStartup() {
	window->draw(loadingBarBorder);
	window->draw(loadingBarFill);
	window->draw(contentName);
	window->draw(percentComplete);
	
}

void Engine::drawTitle() {
	std::vector<sf::Text*> text;
	text = title->getDrawableText();
	std::vector<sf::Sprite*> sprite;
	sprite = title->getDrawableSprite();
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
	for (unsigned i = 0; i < text.size(); window->draw(*text[i++]));
}

void Engine::drawOverworld() {
	std::vector<sf::Sprite*> sprite;
	sprite = currentMap->getDrawableSprite();
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
}

void Engine::drawCombatStart() {
	std::vector<sf::Sprite*> sprite;
	sprite = currentMap->getDrawableSprite();
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
}

void Engine::drawCombat() {
	std::vector<sf::RectangleShape*> shape;
	shape = combatEnvironment->getDrawableShape();
	std::vector<sf::Text*> text;
	text = combatEnvironment->getDrawableText();
	std::vector<sf::Sprite*> sprite;
	sprite = combatEnvironment->getDrawableSprite();
	for (unsigned i = 0; i < shape.size(); window->draw(*shape[i++]));
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
	for (unsigned i = 0; i < text.size(); window->draw(*text[i++]));
	if (combatEnvironment->getPhase() == evaluateDamage) combatEnvironment->updateStatus();
}

void Engine::drawCombatEnd() {
	std::vector<sf::RectangleShape*> shape;
	shape = combatEnvironment->getDrawableShape();
	std::vector<sf::Text*> text;
	text = combatEnvironment->getDrawableText();
	std::vector<sf::Sprite*> sprite;
	sprite = combatEnvironment->getDrawableSprite();
	for (unsigned i = 0; i < shape.size(); window->draw(*shape[i++]));
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
	for (unsigned i = 0; i < text.size(); window->draw(*text[i++]));
}

void Engine::drawMenu() {
	std::vector<sf::RectangleShape*> shape;
	shape = menu->getDrawableShape();
	std::vector<sf::Text*> text;
	text = menu->getDrawableText();
	std::vector<sf::Sprite*> sprite;
	sprite = menu->getDrawableSprite();
	for (unsigned i = 0; i < shape.size(); window->draw(*shape[i++]));
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
	for (unsigned i = 0; i < text.size(); window->draw(*text[i++]));
}

void Engine::drawGameOver() {
	/*
	std::vector<sf::RectangleShape*> shape;
	shape = combatEnvironment->getDrawableShape();
	std::vector<sf::Text*> text;
	text = combatEnvironment->getDrawableText();
	std::vector<sf::Sprite*> sprite;
	sprite = combatEnvironment->getDrawableSprite();
	for (unsigned i = 0; i < shape.size(); window->draw(*shape[i++]));
	for (unsigned i = 0; i < sprite.size(); window->draw(*sprite[i++]));
	for (unsigned i = 0; i < text.size(); window->draw(*text[i++]));
	*/
}

void Engine::drawQuit() {
	window->close();
}

void Engine::drawAnimation() {
	switch (animations[0].getType()) {
	case TitleFadeNew:
	case ChangeMap:
	case CombatStart:
	case CombatEnd:
		window->draw(animations[0].getShape());
		break;
	case PlayerAttack:
	case CreatureAttack:
		window->draw(animations[0].getFloatingText());
		break;
	case GameOverFade:
	case VictoryFade:
		window->draw(animations[0].getShape());
		window->draw(animations[0].getFloatingText());
		break;
	}
}

void Engine::startupHandler(sf::Event event) {
	//ignore input
}

void Engine::titleHandler(sf::Event event) {
	switch (title->handleEvent(event)) {
	case 0:
		startAnimation(Animation(TitleFadeNew, this));
		break;
	case 1:
		//TODO: load game
		break;
	default:
		//ignore
		break;
	}
}

void Engine::overworldHandler(sf::Event event) {
	switch (currentMap->handleEvent(event)) {
	case _Overworld:
		//ignore
		break;
	case _CombatStart:
		changeState(_CombatStart);
		combatStart();
		break;
	case _BossCombat: {
		TileBoss tile = currentMap->getCurrentTileBoss();
		if (tile.req->isComplete()) {
			changeState(_CombatStart);
			bossCombatStart(tile.creatureID);
		}
		break;
	}
	case _Menu:
		menu->update();
		changeState(_Menu);
		break;
	}
}

void Engine::combatStartHandler(sf::Event event){
	//ignore input
}

void Engine::combatHandler(sf::Event event) {
	combatEnvironment->handleEvent(event);
}

void Engine::combatEndHandler(sf::Event event)
{
}

void Engine::menuHandler(sf::Event event) {
	switch (menu->handleEvent(event)) {
	case _Overworld:
		changeState(_Overworld);
		break;
	case _Quit:
		changeState(_Quit);
		break;
	case _Menu:
		//ignore
		break;
	}
}

void Engine::gameOverHandler(sf::Event event) {
	if (event.type == sf::Event::KeyReleased) window->close();
}

Engine::Engine(sf::RenderWindow* window) 
	: window(window) {
	startup();
}

void Engine::handleEvent(sf::Event event) {
	if (!animations.empty()) { 
		//ignore input duration animation
	}
	else {
		switch (currentState) {
		case _Startup:
			startupHandler(event);
			break;
		case _Title:
			titleHandler(event);
			break;
		case _Overworld:
			overworldHandler(event);
			break;
		case _CombatStart:
			combatStartHandler(event);
			break;
		case _Combat:
			combatHandler(event);
			break;
		case _CombatEnd:
			combatEndHandler(event);
			break;
		case _Menu:
			menuHandler(event);
			break;
		case _GameOver:
		case _Victory:
			gameOverHandler(event);
			break;
		}
	}
}

void Engine::updateGame(sf::Time elapsed) {
	updateAnimations(elapsed);
	draw();
}

void Engine::loadFonts() {
	ArcadeClassic.loadFromFile("Fonts\\ARCADECLASSIC.ttf");
	Arrows.loadFromFile("Fonts\\Arrows.ttf");
	Cambria.loadFromFile("Fonts\\cambria.ttf");
	JMH_Arkham.loadFromFile("Fonts\\JMH Arkham.ttf");
	Lady_Radical_2.loadFromFile("Fonts\\Lady Radical 2.ttf");
	PixelFJ_Verdana.loadFromFile("Fonts\\PixelFJVerdana12pt.ttf");
	filesLoaded += 6;
}

void Engine::loadMetadata() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Metadata")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		std::ifstream file;
		file.open("Metadata\\" + files[i]);
		json j;
		file >> j;
		metadata = new Metadata();
		metadata->gameTitle = j.at("Name").get<std::string>();
		file.close();
	}
	filesLoaded += files.size();
}

void Engine::loadTextures() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Textures")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("Textures\\" + files[i]);
		textures.push_back(texture);
	}
	filesLoaded += files.size();
}

void Engine::loadMaps() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Maps")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		std::string path = "Maps\\" + files[i];
		maps.push_back(new Map(path, textures[1], flags, this));
	}
	currentMap = maps[0];
	filesLoaded += files.size();
}

void Engine::loadCreatures() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Creatures")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		std::ifstream inFile;
		std::string path = "Creatures\\" + files[i];
		inFile.open(path);
		json j;
		inFile >> j;
		int amount = j.at("Amount").get<int>();
		for (unsigned k = 0; k < amount; k++) {
			std::string creatureNumber = std::to_string(k);
			creatures.push_back(new Creature(j.at(creatureNumber).at("Name").get<std::string>(),
				j.at(creatureNumber).at("Level").get<unsigned>(),
				j.at(creatureNumber).at("Hitpoints").get<int>(),
				j.at(creatureNumber).at("Strength").get<unsigned>(),
				j.at(creatureNumber).at("EXP").get<unsigned>(),
				j.at(creatureNumber).at("Biome").get<std::string>(),
				j.at(creatureNumber).at("hasFlag").get<bool>(),
				flags[j.at(creatureNumber).at("Flag").get<int>()],
				j.at(creatureNumber).at("isBoss").get<bool>()));
		}
		inFile.close();
	}
	filesLoaded += files.size();
}

void Engine::loadItems() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Items")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		//TODO:
	}
	filesLoaded += files.size();
}

void Engine::loadFlags() {
	std::vector<std::string> files;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("Flags")) != NULL) {
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i > -1) {
				files.push_back(ent->d_name);
				i++;
			}
			else {
				i++;
			}
		}
		closedir(dir);
	}
	for (unsigned i = 0; i < files.size(); i++) {
		std::ifstream file;
		std::string path = "Flags\\" + files[i];
		file.open(path);
		if (file.is_open()) {
			json j;
			file >> j;
			unsigned amount = j.at("Amount").get<unsigned>();
			flags.reserve(amount);
			for (unsigned k = 0; k < amount; k++) {
				if (k == 0) {
					flags.push_back(new Flag());
				}
				else {
					std::string flagNumber = std::to_string(k);
					unsigned req = j.at(flagNumber).at("Req").get<unsigned>();
					flags.push_back(new Flag(flags[req]));
				}
			}
		}
	}
	filesLoaded += files.size();
}

void Engine::createTitle() {
	title = new Title(Lady_Radical_2, PixelFJ_Verdana, Arrows, textures[0]);
	title->setTitle(metadata->gameTitle);
}

void Engine::createMenu() {
	menu = new Menu(JMH_Arkham, Arrows, party);
}

void Engine::createParty() {
	party.push_back(new PlayerCharacter("Respa", textures[1], 1));
	party.push_back(new PlayerCharacter("Pieron", textures[1], 2));
	party.push_back(new PlayerCharacter("Miles", textures[1], 3));
	party.push_back(new PlayerCharacter("Luna", textures[1], 4));
}
