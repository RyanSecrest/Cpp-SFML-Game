#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 6.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->attackCooldownMax2 = 50.f;
	this->attackCooldown2 = this->attackCooldownMax2;

	this->healthPointsMax = 15;
	this->healthPoints = this->healthPointsMax;
}

void Player::initTexture()
{
	//Load texture from file
	if (!this->texture.loadFromFile("Textures/Player.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(900, 800);

	//Rezize the sprite

}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

//Getters and setters
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

int Player::getHealth()
{
	return this->healthPoints;
}

int Player::getHealthMax()
{
	return this->healthPointsMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

//Functions
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

const bool Player::canAttack2()
{
	if (this->attackCooldown2 >= this->attackCooldownMax2)
	{
		this->attackCooldown2 = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;

	if (this->attackCooldown2 < this->attackCooldownMax2)
		this->attackCooldown2 += 0.5f;
}

void Player::update()
{
	

	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
