#ifndef ICOLLISION_HPP
#define ICOLLISION_HPP

#include <SFML/Graphics.hpp>

class ICollision
{
private: 
	float collisionRadius;
public:
	virtual ~ICollision() = default;

	virtual sf::Vector2f getCollisionPosition() const = 0;
	virtual float getRadius() const = 0;
	virtual void onDamage(int damage) = 0;
	virtual void onHit() = 0;
};

#endif // !ICOLLISION_HPP