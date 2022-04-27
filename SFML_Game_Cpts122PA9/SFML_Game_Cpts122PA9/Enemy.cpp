#include "Enemy.h"

void Enemy::initVariables()
{
	this->healthMax=1;
	this->health = this->healthMax;
	this->damage=1;
	this->points=1;
}

void Enemy::initTexture()
{
	//Load texture from file
	if (!this->textureEnemy1.loadFromFile("Textures/Enemy1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Enemy::initSprite()
{
	//Set the texture to the sprite
	this->spriteEnemy1.setTexture(this->textureEnemy1);

	//Rezize the sprite
}

Enemy::Enemy() // doesn't get called
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	
}

Enemy::Enemy(float posX, float posY)
{
	//this->initShape();
	this->initVariables();
	this->initTexture();
	this->initSprite();
	spriteEnemy1.scale(1.f, 1.f);
	spriteEnemy1.setPosition(sf::Vector2f(posX, posY));
	//this->shape.setPosition(posX, posY);
	
}

Enemy::~Enemy()
{

}

//Getter setters
const sf::FloatRect Enemy::getBounds() const
{
	return this->spriteEnemy1.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

//Functions
void Enemy::update()
{
	this->spriteEnemy1.move(0.f, 2.5f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->spriteEnemy1);
	
}

Boss::Boss() // doesn't get called
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	
}

Boss::Boss(float posX, float posY)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	spriteBoss.scale(1.7f, 1.7f);
	spriteBoss.setPosition(sf::Vector2f(posX, posY));
}

Boss::~Boss()
{
}

const sf::FloatRect Boss::getBounds() const
{
	sf::FloatRect bounds;
	return this->spriteBoss.getGlobalBounds();
}

const int& Boss::getPoints() const
{
	return this->points;
}

void Boss::initVariables()
{
	this->healthMax = 15;
	this->health = this->healthMax;
	this->damage = 3;
	this->points = 5;
}

void Boss::initTexture()
{
	//Load texture from file
	if (!this->textureBoss.loadFromFile("Textures/Enemy2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Boss::initSprite()
{
	//Set the texture to the sprite
	this->spriteBoss.setTexture(this->textureBoss);

	//Rezize the sprite
}

void Boss::update()
{
	this->spriteBoss.move(0.f, 1.f);
}

void Boss::render(sf::RenderTarget* target)
{
	target->draw(this->spriteBoss);
}

void EnemyFinal::initVariables()
{
	this->healthMax = 30;
	this->health = this->healthMax;
	this->damage = 10;
	this->points = 10;
}

void EnemyFinal::initTexture()
{
	//Load texture from file
	if (!this->textureFinal.loadFromFile("Textures/EnemyFinal.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void EnemyFinal::initSprite()
{
	//Set the texture to the sprite
	this->spriteFinal.setTexture(this->textureFinal);

	//Rezize the sprite
}

EnemyFinal::EnemyFinal()
{

}

EnemyFinal::EnemyFinal(float posX, float posY)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	spriteFinal.scale(2.f, 2.f);
	spriteFinal.setPosition(sf::Vector2f(posX, posY));
}

EnemyFinal::~EnemyFinal()
{

}

const sf::FloatRect EnemyFinal::getBounds() const
{
	return this->spriteFinal.getGlobalBounds();
}

const int& EnemyFinal::getPoints() const
{
	return this->points;
}

void EnemyFinal::update()
{
	this->spriteFinal.move(0.f, 0.3f);
}

void EnemyFinal::render(sf::RenderTarget* target)
{
	target->draw(this->spriteFinal);
}
