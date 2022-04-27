#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

class Player
{
private:
	//360 Shooting variables
	sf::Vector2f player1Center;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	//Other
	sf::Sprite sprite;
	sf::Texture texture;
	
	//Attribute
	int healthPoints;
	int healthPointsMax;
	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;
	float attackCooldown2;
	float attackCooldownMax2;

	//Private Functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	//Getters and setters
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	int getHealth();
	int getHealthMax();

	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);

	//Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();
	const bool canAttack2();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

