#include "Projectile2.h"

Projectile2::Projectile2()
{
}

Projectile2::Projectile2(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed_l)
{
	this->spriteMissile.setTexture(*texture);

	this->spriteMissile.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed_l;

	this->spriteMissile.setScale(5.f, 5.f);
}

Projectile2::~Projectile2()
{

}

const sf::FloatRect Projectile2::getBounds() const
{
	return this->spriteMissile.getGlobalBounds();
}

void Projectile2::update()
{
	this->spriteMissile.move(this->movementSpeed * this->direction);
}

void Projectile2::render(sf::RenderTarget* target)
{
	target->draw(this->spriteMissile);
}
