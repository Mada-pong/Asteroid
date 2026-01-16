#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "ICollision.h"

class Entity : public sf::Drawable, public sf::Transformable, public ICollision
{

private: 
	sf::CircleShape sphereShape;
	sf::Vector2f position;
	sf::Vector2f scale;
	float angle;

	bool markedForRemoval = false;
protected:
	sf::CircleShape getSphereShape() const { return sphereShape; }
public:
	Entity(sf::Vector2f startPosition, sf::Color color, float radius);

	sf::Vector2f getPosition() const { return position; }
	void setPosition(sf::Vector2f vector);
	void move(sf::Vector2f delta);

	void setScale(sf::Vector2f vectorScale);
	sf::Vector2f getScale() const { return scale; }

	bool isMarkedForRemoval() const { return this->markedForRemoval; }
	void setMarkedForRemoval() { this->markedForRemoval = true; }

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//// Inherited via ICollision
	sf::Vector2f getCollisionPosition() const override { return getPosition(); }
	float getRadius() const override { return sphereShape.getRadius(); }
	void onDamage(int damage) override;
	void onHit() override;
};

#endif 
