#pragma once
#include "Map.hpp"
#include "Menu.hpp"
#include "Title.hpp"
#include "Combat.hpp"
#include "Creature.hpp"
#include "Metadata.hpp"
#include "Animation.hpp"

class Map;
class Menu;
class Combat;
class Animation;
class PlayerCharacter;

enum GameState {
	_Startup,
	_Title,
	_Overworld,
	_CombatStart,
	_Combat,
	_CombatEnd,
	_Menu,
	_GameOver,
	_Quit,
};

class Engine {
public:
//Constructor
	Engine(sf::RenderWindow* window);

//Methods
	void handleEvent(sf::Event event);
	void updateGame(sf::Time elapsed);
	void changeState(GameState state);
	void startAnimation(Animation animation);
	void changeCurrentMap(unsigned id);

private:
//Heap storage for assets
	std::vector<sf::Texture*> textures;
	std::vector<Map*> maps;
	std::vector<Creature*> creatures;
	//std::vector<Item*> items;
	std::vector<Flag*> flags;
	
	Metadata* metadata;

//Load assets
	/*\brief Loads font files from ..\Fonts\ folder and stores them in sf::Font class
	This must happen before anything else because the startup screen needs the font in
	order to display the loading progress*/
	void loadFonts();

	/*\brief Loads metadata files from ..\Metadata\ folder and stores data in Metadata class*/
	void loadMetadata();

	/*\brief Loads texture files from ..\Textures\ folder and stores data in std::vector<Texture*>*/
	void loadTextures();

	/*\brief Loads map files from ..\Maps\ folder and stores data in std::vector<Map*>*/
	void loadMaps();

	/*\brief Loads creature files from ..\Creatures\ folder and stores data in std::vector<Creature*>*/
	void loadCreatures();

	/*\brief Loads item files from ..\Items\ folder and stores data in std::vector<Item*>*/
	void loadItems();

	/*\brief Loads flag files from ..\Flags\ folder and stores data in std::vector<Flag*>*/
	void loadFlags();

//Link assets to graphical components
	void createTitle();

	//part must be created before menu
	void createParty();
	void createMenu();

//Window
	sf::RenderWindow* window;

//Members
	GameState currentState = _Startup;
	double totalFiles = 0;
	double filesLoaded = 0;
	std::vector<Animation> animations;

//Environments
	//Title
	Title* title;

	//Map environment variables
	Map* currentMap;
	unsigned currentMapID;

	//Combat environment variables
	Combat* combatEnvironment;

	//Menu
	Menu* menu;

//Party
	std::vector<PlayerCharacter*> party;

//Graphics components
	//Fonts
	sf::Font ArcadeClassic;
	sf::Font Arrows;
	sf::Font Cambria;
	sf::Font JMH_Arkham;
	sf::Font Lady_Radical_2;
	sf::Font PixelFJ_Verdana;

	//Startup
	sf::Text contentName;
	sf::Text percentComplete;
	
	sf::RectangleShape loadingBarBorder;
	sf::RectangleShape loadingBarFill;

//Methods
	void startup();

	/*\brief Counts the total number of files to be loaded at startup
	and sets Engine.totalFiles to this number*/
	void countFiles();

	void draw();
	void updateAnimations(sf::Time elapsed);
	void combatStart();

//Draw
	void drawStartup();
	void drawTitle();
	void drawOverworld();
	void drawCombatStart();
	void drawCombat();
	void drawCombatEnd();
	void drawMenu();
	void drawGameOver();
	void drawQuit();
	void drawAnimation();

//Event handlers
	void startupHandler(sf::Event event);
	void titleHandler(sf::Event event);
	void overworldHandler(sf::Event event);
	void combatStartHandler(sf::Event event);
	void combatHandler(sf::Event event);
	void combatEndHandler(sf::Event event);
	void menuHandler(sf::Event event);
	void gameOverHandler(sf::Event event);
};