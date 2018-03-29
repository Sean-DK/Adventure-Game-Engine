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
//Constructor
	Engine(sf::RenderWindow* window);

//Methods
	void handleEvent(sf::Event event);
	void updateGame(sf::Time elapsed);

private:
//Heap storage for assets
	std::vector<sf::Texture*> textures;
	//std::vector<Map*> maps;
	//std::vector<Creature*> creatures;
	//std::vector<Item*> items;
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
	//std::vector<Flag*> flags;
	/*
	class Metadata {
		public:
			Metadata();

		private:
			std::string gameTitle;
			unsigned numOfTextures;
			unsigned numOfMaps;
			unsigned numOfCreatures;
			unsigned numOfItems;
			unsigned numOfFlags;
	*/
	//Metadata* metadata;

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

//Window
	sf::RenderWindow* window;

//Members
	GameState currentState = Startup;
	double totalFiles = 0;
	double filesLoaded = 0;
	//std::vector<Animation> animations;

//Environments
	//Map environment variables
	//Map* currentMap;
	unsigned currentMapID;

	//Combat environment variables
	//Combat* combatEnvironment;
	//std::vector<Creature> combatEnemies;

	//Inventory variables
	//std::vector<Item> inventory;

//Party
	//std::vector<PlayerCharacter*> party;

//Graphics components
	//Fonts
	sf::Font ArcadeClassic;
	sf::Font Cambria;
	sf::Font JMH_Arkham;
	sf::Font Lady_Radical_2;
	sf::Font PixelFJ_Verdana;

	//Startup
	sf::Text contentName;
	sf::Text percentComplete;
	
	sf::RectangleShape loadingBarBorder;
	sf::RectangleShape loadingBarFill;

	//Title
	sf::Text gameTitle;
	sf::Text newGame;
	sf::Text loadGame;
	
	sf::Sprite background;

	//Combat
	sf::Text creatureOneName;
	sf::Text creatureTwoName;
	sf::Text creatureThreeName;
	sf::Text creatureFourName;
	sf::Text creatureFiveName;
	sf::Text creatureSixName;

	sf::Text partyOneStatus;
	sf::Text partyTwoStatus;
	sf::Text partyThreeStatus;
	sf::Text partyFourStatus;

	sf::Text optionAttack;
	sf::Text optionMagic;
	sf::Text optionItem;
	sf::Text optionFlee;
	std::vector<sf::Text> options;

	sf::RectangleShape statusBackdrop;
	sf::RectangleShape optionsBackdrop;
	
	//sf::Sprite background;

	sf::Sprite creatureOneSprite;
	sf::Sprite creatureTwoSprite;
	sf::Sprite creatureThreeSprite;
	sf::Sprite creatureFourSprite;
	sf::Sprite creatureFiveSprite;
	sf::Sprite creatureSixSprite;
	sf::Sprite bossSprite;

	sf::Sprite partyOneSprite;
	sf::Sprite partyTwoSprite;
	sf::Sprite partyThreeSprite;

	sf::Text floatingDamageText;

	//Menu
	sf::Text optionResume;
	sf::Text optionInventory;
	sf::Text optionEqupiment;
	sf::Text optionSave;
	sf::Text optionQuit;
	//std::vector<sf::Text> options;

	sf::Text partyOneNameAndLevel;
	sf::Text partyOneHP;
	sf::Text partyOneMP;
	sf::Text partyOneXP;

	sf::Text partyTwoNameAndLevel;
	sf::Text partyTwoHP;
	sf::Text partyTwoMP;
	sf::Text partyTwoXP;

	sf::Text partyThreeNameAndLevel;
	sf::Text partyThreeHP;
	sf::Text partyThreeMP;
	sf::Text partyThreeXP;

	sf::Text partyFourNameAndLevel;
	sf::Text partyFourHP;
	sf::Text partyFourMP;
	sf::Text partyFourXP;

	//sf::Sprite partyOneSprite;
	//sf::Sprite partyTwoSprite;
	//sf::Sprite partyThreeSprite;
	//sf::Sprite partyFourSprite;

//Methods
	void startup();

	/*\brief Counts the total number of files to be loaded at startup
	and sets Engine.totalFiles to this number*/
	void countFiles();

	void draw();
	void updateAnimations(sf::Time elapsed);
	void combatStart();
	//void startAnimation(Animation animation);
	void changeState(GameState state);

//Draw
	void drawStartup();
	void drawTitle();
	void drawOverworld();
	void drawCombatStart();
	void drawCombat();
	void drawCombatEnd();
	void drawMenu();
	void drawGameOver();

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