#include "Projectile.h"

class Projectile2 : public Projectile
{
private:
	//Attributes
	//Texture + Sprite
	sf::Sprite spriteMissile;
	sf::Texture* textureMissile;

	sf::Vector2f direction;
	float movementSpeed;

public:
	//Constructors and Destructors
	Projectile2(); // default
	Projectile2(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed_l);
	virtual ~Projectile2();

	//Getters and setters
	const sf::FloatRect getBounds() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);

};

