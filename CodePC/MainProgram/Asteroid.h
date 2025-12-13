#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Asteroid : public Entity
{
private: 
	float baseSpeed = 5;
	float baseRotationSpeed = 10;
public: 
	void update() override;
	Asteroid(sf::Vector2f startPosition, sf::Vector2f centerPosition,sf::Color color, float radius);

	void Move();
};

#endif // !ASTEROID_HPP