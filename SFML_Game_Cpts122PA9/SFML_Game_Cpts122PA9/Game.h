#pragma once

#include <map>

#include "Player.h"
#include "Projectile2.h"
#include "Enemy.h"
#include "Menu.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources

	//Network
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char type;

	//Textures
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::Texture*> texturesMissile;
	std::map<std::string, sf::Texture*> texturesEnemy1;
	std::map<std::string, sf::Texture*> texturesEnemy2;
	std::vector<Projectile*> projectiles;
	std::vector<Projectile2*> projectiles2;

	//Audio
	sf::Music music;
	sf::SoundBuffer pop;
	sf::SoundBuffer bloop;
	sf::SoundBuffer missileLaunch;
	sf::SoundBuffer crash;
	sf::SoundBuffer deflect;

	sf::Sound popSound;
	sf::Sound bloopSound;
	sf::Sound missileLaunchSound;
	sf::Sound crashSound;
	sf::Sound deflectSound;

	//Sidebar GUI
	sf::RectangleShape guiBar;
	sf::RectangleShape guiBarOutline;

	sf::Text instructions;
	sf::Text pointText;
	sf::Text healthText;
	sf::Font font;

	//Player 
	Player* player1;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	//Attributes
	unsigned points;

	//Enemies/Game objects
	std::vector<Enemy*> enemies;
	std::vector<Boss*> enemies2;
	std::vector<EnemyFinal*> enemyFinal;
	sf::Texture enemy1Texture;
	sf::Sprite enemy1;
	
	// sf::RectangleShape enemy; circles are cooler than rectangles

	//Text
	sf::Text uiText;
	sf::Text gameOverText;

	//Game Logic
	bool endGame;
	
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	float bossSpawnTimer;
	float bossSpawnTimerMax;
	float finalSpawnTimer;
	float finalSpawnTimerMax;
	int maxBosses;
	int maxEnemies;

	//Private Functions
	void initFonts();
	void initWindow();
	void initAudio();
	void initTextures();
	void initVariables();
	void initText();
	void initEnemies();
	void initGui();

	void initPlayer();

public:
	//Constructors and destructors
	Game();
	virtual ~Game();

	//Getter setters
	const bool getEndGame() const;
	void setType(char* pType);
	char getType();

	//Functions
	void spawnEnemy();

	void run();

	void updateMousePositions();
	void updateText();
	void updateGui();
	void updateEnemiesAndHitReg();
	void updateEnemiesAndHitReg2();
	void updateEnemiesAndHitReg3();	
	void updateCollision();
	void updatePollEvents();
	void updateInput();
	void updateProjectiles();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderGui();
	void renderEnemies(sf::RenderTarget& target);
	void render();

};

