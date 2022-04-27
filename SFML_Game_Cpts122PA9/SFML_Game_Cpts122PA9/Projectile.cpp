#include "Projectile.h"

//Constructors and Destructors
Projectile::Projectile()
{
	
}

Projectile::Projectile(sf::Texture * texture, float posX, float posY, float dirX, float dirY, float movementSpeed_l)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed_l;
}

Projectile::~Projectile()
{

}

const sf::FloatRect Projectile::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const float& Projectile::getMovementSpeed() const
{
	return this->movementSpeed;
}

//Functions
void Projectile::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void Projectile::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
