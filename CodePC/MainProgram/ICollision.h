#ifndef ICOLLISION_HPP
#define ICOLLISION_HPP

#include <SFML/Graphics.hpp>

class ICollision
{
private: 
	float collisionRadius;
public:
	~ICollision();

	virtual sf::Vector2f getPosition() const = 0;
	virtual float getRadius() const = 0;
	virtual void onDamage(int damage) = 0;
	virtual void onHit() = 0;
};

#endif // !ICOLLISION_HPP