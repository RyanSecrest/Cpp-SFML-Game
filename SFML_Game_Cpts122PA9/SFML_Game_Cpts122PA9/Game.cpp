#include "Game.h"

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pixel.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!"<<"\n";
	}
}

//Private Functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Box Invasion", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initAudio()
{
	if (!bloop.loadFromFile("Audio/bloop.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";

	if (!pop.loadFromFile("Audio/pop.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";

	if (!missileLaunch.loadFromFile("Audio/missileLaunch.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";

	if (!crash.loadFromFile("Audio/crash.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";

	if (!deflect.loadFromFile("Audio/deflect.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";
	
	if (!music.openFromFile("Audio/titleWithDrumsDemo.WAV"))
		std::cout << "ERROR::GAME::INITAUDIO::Failed to load audio!";

	music.play();
	music.setLoop(true);
}

void Game::initTextures()
{
	this->textures["Projectile"] = new sf::Texture();
	this->textures["Projectile"]->loadFromFile("Textures/Projectile2.png");

	this->texturesMissile["ProjectileMissile"] = new sf::Texture();
	this->texturesMissile["ProjectileMissile"]->loadFromFile("Textures/projectileMissle.png");
}

void Game::initVariables()
{
	this->points = 0;
	this->health = 30;
}

void Game::initText()
{

}

void Game::initEnemies()
{
	this->enemySpawnTimerMax = 40.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;

	this->bossSpawnTimerMax = 80.f;
	this->bossSpawnTimer = 0.f;

	this->finalSpawnTimerMax = 250.f;
	this->finalSpawnTimer = 0.f;
}

void Game::initGui()
{
	//side bar
	this->guiBar.setFillColor(sf::Color(16,24,32,220));
	this->guiBar.setPosition(sf::Vector2f(0.f,0.f));
	this->guiBar.setSize(sf::Vector2f(350.f, 1080.f));

	this->guiBarOutline.setFillColor(sf::Color::White);
	this->guiBarOutline.setPosition(sf::Vector2f(351.f, 0.f));
	this->guiBarOutline.setSize(sf::Vector2f(20.f, 1080.f));
	//Points
	

	//Health
	
	//Game over
	this->gameOverText.setFont(font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setPosition(700, 500);
	this->gameOverText.setString("GAME OVER");
}

void Game::initPlayer()
{
	this->player1 = new Player();

	
}

//Constructor and Destructor
Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initAudio();
	this->initTextures();
	this->initFonts();
	this->initGui();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player1;

	//Delete textures
	for (auto &i : this->textures)
	{
		delete i.second;
	}

	//Delete Projectiles
	for (auto* i : this->projectiles)
	{
		delete i;
	}

	//Delete enemies
	for (auto* i : this->enemies) // basic enemy
	{
		delete i;
	}

	for (auto* i : this->enemies2) // red square enemy
	{
		delete i;
	}

	for (auto* i : this->enemyFinal) // yellow final boss
	{
		delete i;
	}
}

//Getter setters

const bool Game::getEndGame() const
{
	return false;
}

void Game::setType(char* pType)
{
	this->type = *pType;
}

char Game::getType()
{
	return this->type;;
}

//Functions


void Game::spawnEnemy()
{
}

void Game::run()
{

	//Game loop
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::updateMousePositions()
{
}

void Game::updateText()
{
}

void Game::updateGui()
{
	//Instructions
	std::stringstream ssT;

	ssT << "How to Play: \n\nWASD to move\nLeft Click +\nRight Click\nTo Shoot\n\nGOOD LUCK!";

	this->instructions.setString(ssT.str());
	this->instructions.setFont(font);
	this->instructions.setFillColor(sf::Color(254, 231, 21, 255));
	this->instructions.setCharacterSize(24);
	this->instructions.setPosition(3.f, 500.f);

	//Points 
	std::stringstream ss;

	ss << "Points: " << this->points;

	this->pointText.setString(ss.str());

	this->pointText.setFont(font);
	this->pointText.setFillColor(sf::Color(254,231,21,255));
	this->pointText.setCharacterSize(40);
	this->pointText.setPosition(3.f, 10.f);

	//Health
	std::stringstream ss2;

	ss2 << "Health: " << this->health;

	this->healthText.setString(ss2.str());
		 
	this->healthText.setFont(font);
	this->healthText.setFillColor(sf::Color(254, 231, 21, 255));
	this->healthText.setCharacterSize(40);
	this->healthText.setPosition(3.f, 200.f);

	//Game over

}

void Game::updateEnemiesAndHitReg()
{
	this->enemySpawnTimer += 0.7f;
	if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	{
		this->enemies.push_back(new Enemy(
			rand() % 1400 +320.f, -40.f));
		this->enemySpawnTimer = 0.f;
	}
	
	//Hit registration
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false; //bool to prevent crashing
		this->enemies[i]->update();
		
		for (size_t k = 0; k < this->projectiles.size() && !enemy_removed; k++)
		{
			if (this->projectiles[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				this->projectiles.erase(this->projectiles.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);

				this->popSound.setBuffer(pop);
				this->popSound.setVolume(20.f);
				this->popSound.setPlayingOffset(sf::seconds(1.f));
				this->popSound.play();

				enemy_removed = true;
			}
		}

		//Remove enemy at the bottom of the screen
		if (!enemy_removed)
		{
			if (this->enemies[i]->getBounds().top > this->window->getSize().y)
			{
				this->enemies.erase(this->enemies.begin() + i);
				this->health = this->health - 1;
				enemy_removed = true;
			}
		}
	}
}

void Game::updateEnemiesAndHitReg2()
{
	this->bossSpawnTimer += 0.1f;
	if (this->bossSpawnTimer >= this->bossSpawnTimerMax)
	{
		this->enemies2.push_back(new Boss(
			rand() % 1200 + 320.f , -100.f));
		this->bossSpawnTimer = 0.f;
	}

	//Hit registration
	for (int i = 0; i < this->enemies2.size(); ++i)
	{
		bool enemy_removed2 = false; //bool so that we don't crash
		this->enemies2[i]->update();

		for (size_t k = 0; k < this->projectiles2.size() && !enemy_removed2; k++)
		{
			if (this->projectiles2[k]->getBounds().intersects(this->enemies2[i]->getBounds()))
			{
				this->points += this->enemies2[i]->getPoints();

				this->projectiles2.erase(this->projectiles2.begin() + k);
				this->enemies2.erase(this->enemies2.begin() + i);

				this->crashSound.setBuffer(crash);
				this->crashSound.setVolume(13.f);
				this->crashSound.setPlayingOffset(sf::seconds(4.f));
				this->crashSound.play();

				enemy_removed2 = true;
			}
		}

		//Remove enemy at the bottom of the screen
		if (!enemy_removed2)
		{
			if (this->enemies2[i]->getBounds().top > this->window->getSize().y)
			{
				this->enemies2.erase(this->enemies2.begin() + i);
				this->health = this->health - 5;
				enemy_removed2 = true;
			}
		}
	}
}

void Game::updateEnemiesAndHitReg3()
{
	this->finalSpawnTimer += 0.1f;
	if (this->finalSpawnTimer >= this->finalSpawnTimerMax)
	{
		this->enemyFinal.push_back(new EnemyFinal(
			rand() % 1100 + 320.f, -100.f));
		this->finalSpawnTimer = 0.f;
	}

	//Hit registration
	for (int i = 0; i < this->enemyFinal.size(); ++i)
	{
		bool enemy_removed3 = false; //bool so that we don't crash
		this->enemyFinal[i]->update();

		for (size_t k = 0; k < this->projectiles2.size() && !enemy_removed3; k++)
		{
			if (this->projectiles2[k]->getBounds().intersects(this->enemyFinal[i]->getBounds()))
			{
				this->points += this->enemyFinal[i]->getPoints();

				this->projectiles2.erase(this->projectiles2.begin() + k);
				this->enemyFinal.erase(this->enemyFinal.begin() + i);

				this->crashSound.setBuffer(crash);
				this->crashSound.setVolume(13.f);
				this->crashSound.setPlayingOffset(sf::seconds(4.f));
				this->crashSound.play();

				this->enemies2.push_back(new Boss(
					rand() % 1200 + 320.f, 300.f));
				this->enemies2.push_back(new Boss(
					rand() % 1200 + 320.f, 300.f));
				this->enemies2.push_back(new Boss(
					rand() % 1200 + 320.f, 300.f));

				enemy_removed3 = true;
			}
		}

		//Remove enemy at the bottom of the screen
		if (!enemy_removed3)
		{
			if (this->enemyFinal[i]->getBounds().top > this->window->getSize().y)
			{
				this->enemyFinal.erase(this->enemyFinal.begin() + i);
				this->health = this->health - 20;
				enemy_removed3 = true;
			}
		}
	}
}

void Game::updateCollision()
{
	//Player

	//left
	if (this->player1->getBounds().left < 320.f)
	{
		this->player1->setPosition(320.f, this->player1->getBounds().top);
	}

	//right
	else if (this->player1->getBounds().left + this->player1->getBounds().width - 30.f >= this->window->getSize().x)
	{
		this->player1->setPosition(this->window->getSize().x - this->player1->getBounds().width + 30.f, this->player1->getBounds().top);
	}

	//top
	if (this->player1->getBounds().top < 0.f)
	{
		this->player1->setPosition(this->player1->getBounds().left, 0.f);
	}

	//bottom
	else if (this->player1->getBounds().top + this->player1->getBounds().height >= this->window->getSize().y)
	{
		this->player1->setPosition(this->player1->getBounds().left, this->window->getSize().y - this->player1->getBounds().height);
	}

	//Enemies

	//right
	
}

void Game::updatePollEvents()
{
	sf::Event e;

	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player1->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player1->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player1->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player1->move(0.f, 1.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player1->canAttack())
	{
		this->projectiles.push_back(
		new Projectile(
		this->textures["Projectile"], 
		this->player1->getPos().x + this->player1->getBounds().width /3.f , 
		this->player1->getPos().y,
		0.f, -1.f, 5.f));
		
		this->bloopSound.setBuffer(bloop);
		this->bloopSound.setVolume(5.f);
		this->bloopSound.setPlayingOffset(sf::seconds(1.f));
		this->bloopSound.play();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->player1->canAttack2())
	{
		this->projectiles2.push_back(
			new Projectile2(
				this->texturesMissile["ProjectileMissile"],
				this->player1->getPos().x + this->player1->getBounds().width -120.f,
				this->player1->getPos().y,
				0.f, -0.5f, 5.f));

		this->missileLaunchSound.setBuffer(missileLaunch);
		this->missileLaunchSound.setPlayingOffset(sf::seconds(1.f));
		this->missileLaunchSound.setVolume(50.f);
		this->missileLaunchSound.play();
	}
}

void Game::updateProjectiles()
{
	unsigned counter = 0;
	for (auto* projectile : this->projectiles)
	{
		projectile->update();

		//Projectile wont go out of screen
		if (projectile->getBounds().top + projectile->getBounds().height < 0.f)
		{
			//Delete projectile
			delete this->projectiles.at(counter);
			this->projectiles.erase(this->projectiles.begin() + counter);
			--counter;
		}

		++counter;
	}

	unsigned counter2 = 0;
	for (auto* projectile2 : this->projectiles2)
	{
		projectile2->update();

		//Projectile wont go out of screen
		if (projectile2->getBounds().top + projectile2->getBounds().height < 0.f)
		{
			//Delete projectile
			delete this->projectiles2.at(counter2);
			this->projectiles2.erase(this->projectiles2.begin() + counter2);
			--counter2;
		}

		++counter2;
	}
}

void Game::update()
{
	this->updatePollEvents();

	this->updateInput();

	this->player1->update();

	this->updateCollision();

	this->updateProjectiles();

	this->updateEnemiesAndHitReg();
	this->updateEnemiesAndHitReg2();
	this->updateEnemiesAndHitReg3();

	this->updateGui();
}

void Game::renderText(sf::RenderTarget& target)
{

}

void Game::renderGui()
{
	this->window->draw(this->guiBar);
	this->window->draw(this->pointText);
	this->window->draw(this->healthText);
	this->window->draw(this->instructions);

	if (this->health <= 0)
	{
		this->window->draw(this->gameOverText);
	}
}

void Game::renderEnemies(sf::RenderTarget& target)
{

}

void Game::render()
{
	this->window->clear();

	this->window->clear(sf::Color::Cyan);

	//Draw objects
	this->player1->render(*this->window);

	for (auto* projectile : this->projectiles)
	{
		projectile->render(this->window);
	}

	for (auto* projectile2 : this->projectiles2)
	{
		projectile2->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* enemy2 : this->enemies2)
	{
		enemy2->render(this->window);
	}

	for (auto* enemy3 : this->enemyFinal)
	{
		enemy3->render(this->window);
	}

	this->renderGui();

	this->window->display();
}
