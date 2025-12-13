#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Asteroid : public Entity
{
private: 
	float baseSpeed = 5;
	float baseRotationSpeed = 10;

	sf::Vector2f targetPosition;
	sf::Vector2f targetDirection; 
public: 
	void update() override;
	Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float size);

	void Movement();
};

#endif // !ASTEROID_HPP