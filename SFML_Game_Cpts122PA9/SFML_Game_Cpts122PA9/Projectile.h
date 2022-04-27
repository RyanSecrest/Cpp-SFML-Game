#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <iostream>

class Projectile
{
private:
	//Texture + Sprite
	sf::Sprite shape;
	sf::Texture* texture;

	sf::Vector2f direction;
	float movementSpeed;

	//Private Functions

public:
	//Constructors and Destructors
	Projectile(); // default
	Projectile(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Projectile();

	//Getters and setters
	const sf::FloatRect getBounds() const;
	const float& getMovementSpeed() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif // ^^

