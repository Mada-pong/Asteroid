#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
private:
	sf::CircleShape sphereShape;
	sf::Vector2f vector2;

public:
	Entity();

	sf::Vector2f getPosition() const { return vector2; };
	void setPosition(sf::Vector2f vector); 

	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif 
