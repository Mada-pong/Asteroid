#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "VectorUtility.h"

class Entity : public sf::Drawable, public sf::Transformable
{
protected:
	sf::CircleShape sphereShape;
	sf::Vector2f vector2;

	float angle;
	sf::Vector2f scale;
public:
	Entity();
	Entity(sf::Vector2f startPosition, sf::Color color, float radius);

	sf::Vector2f getPosition() const { return vector2; };
	void setPosition(sf::Vector2f vector);
	void move(sf::Vector2f vector);

	void setScale(sf::Vector2f vectorScale);
	sf::Vector2f getScale() const { return scale; };

	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif 
