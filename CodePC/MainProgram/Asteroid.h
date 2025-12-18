#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "HealthComponent.h"


//TODO: Remove hard coded values and put it into a file maybe? 
class Asteroid : public Entity
{
private: 
	float baseSpeed = 1;
	float baseRotationSpeed = 10;
	float baseHP = 3;

	HealthComponent healthComponent;

	sf::Vector2f targetPosition;
	sf::Vector2f targetDirection; 

	sf::Vector2f screenBorder;
	sf::Vector2f borderOffset = sf::Vector2f(-400, -500);

public: 
	void update(float deltaTime) override;
	Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float size, float speed, sf::Vector2f screenBorder);

	void isDead() const;
	bool isOutside() const;

	void onDamage(int damage) override;
	void onHit() override;
};

#endif // !ASTEROID_HPP