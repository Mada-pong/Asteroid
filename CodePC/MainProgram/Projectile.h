#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"
#include "VectorUtility.h"

class Projectile : public Entity
{
private: 
	float velocity = 1;
	Cooldown timeToLiveCooldown;

	sf::Vector2f direction;
public:
	void update() override;
	Projectile(sf::Vector2f startPosition, sf::Color color, float radius, float angle, float velocity, float timeToLive);
};

#endif // !

