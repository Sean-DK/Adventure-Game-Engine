#include "stdafx.h"
#include "Engine.h"
#include "Dirent.h"
#include <fstream>

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
	
	/*Load textures*/
	contentName.setString("Loading textures - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	unsigned tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();
	loadTextures();

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

	/*Load flags*/
	contentName.setString("Loading flags - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();
	loadFlags();

	/*Cleanup display*/
	contentName.setString("Finishing up - ");
	tempPos = contentName.getGlobalBounds().left + contentName.getGlobalBounds().width;
	percentComplete.setPosition(sf::Vector2f(tempPos, 210));
	tempPercent = double(filesLoaded / totalFiles) * 100;
	percentComplete.setString(std::to_string(tempPercent) + "%");
	loadingBarFill.setSize(sf::Vector2f(tempPercent * 4, 50));
	draw();

	createTitle();

	sf::Clock tempClock;
	while (tempClock.getElapsedTime().asMilliseconds() < 700) {}
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
	}
	window->display();
}

void Engine::updateAnimations(sf::Time elapsed)
{
}

void Engine::combatStart() {
	//startAnimation(Animation(combatTransitionStart));
	//changeGameState(_CombatStart);
	//startAnimation(Animation(combatTransitionEnd));
}

//void Engine::startAnimation(Animation animation) {

//}

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

void Engine::drawOverworld()
{
}

void Engine::drawCombatStart()
{
}

void Engine::drawCombat()
{
}

void Engine::drawCombatEnd()
{
}

void Engine::drawMenu()
{
}

void Engine::drawGameOver()
{
}

void Engine::startupHandler(sf::Event event) {
	//ignore input on the startup screen
}

void Engine::titleHandler(sf::Event event) {
	switch (title->handleEvent(event)) {
	case 0:
		//TODO: new game
		changeState(_Overworld);
		break;
	case 1:
		//TODO: load game
		break;
	default:
		//ignore
		break;
	}
}

void Engine::overworldHandler(sf::Event event)
{
}

void Engine::combatStartHandler(sf::Event event)
{
}

void Engine::combatHandler(sf::Event event)
{
}

void Engine::combatEndHandler(sf::Event event)
{
}

void Engine::menuHandler(sf::Event event)
{
}

void Engine::gameOverHandler(sf::Event event)
{
}

Engine::Engine(sf::RenderWindow* window) 
	: window(window) {
	startup();
}

void Engine::handleEvent(sf::Event event) {
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
		gameOverHandler(event);
		break;
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
		//TODO: read the file into a data structure
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
		std::ifstream file;
		file.open("Maps\\" + files[i]);
		//TODO: read the file into a data structure
	}
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
		std::ifstream file;
		file.open("Creatures\\" + files[i]);
		//TODO: read the file into a data structure
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
		std::ifstream file;
		file.open("Items\\" + files[i]);
		//TODO: read the file into a data structure
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
		file.open("Flags\\" + files[i]);
		//TODO: read the file into a data structure
	}
	filesLoaded += files.size();
}

void Engine::createTitle() {
	title = new Title(Lady_Radical_2, PixelFJ_Verdana, Arrows, textures[0]);
}
