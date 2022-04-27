#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

class Enemy
{
private:
	//Variables
	//Attributes
	//sf::CircleShape shape;
	sf::Sprite spriteEnemy1;
	sf::Texture textureEnemy1;

	int health;
	int healthMax;
	int damage;
	int points;

	//Private Functions
	void initVariables();
	void initTexture();
	void initSprite();
	//void initShape();

public:
	//Constructors and destructors
	Enemy();
	Enemy(float posX, float posY);
	virtual ~Enemy();

	//Getter setters
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif // !ENEMY_H

class Boss : public Enemy
{
private:
	//Variables

	//Attributes
	sf::Sprite spriteBoss;
	sf::Texture textureBoss;

	int type;
	int health;
	int healthMax;
	int damage;
	int points;

public:
	//Constructors and Destructors
	Boss();
	Boss(float posX, float posY);
	virtual ~Boss();

	//Getter setters
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	//Functions
	void initVariables();
	void initTexture();
	void initSprite();

	void update();
	void render(sf::RenderTarget* target);
};

class EnemyFinal : public Enemy
{
private:
	//Variables
	int type;
	int health;
	int healthMax;
	int damage;
	int points;

	//Attributes
	sf::Sprite spriteFinal;
	sf::Texture textureFinal;

	//Private Functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	//Constructors and Destructors
	EnemyFinal();
	EnemyFinal(float posX, float posY);
	virtual ~EnemyFinal();

	//Getter setters
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

