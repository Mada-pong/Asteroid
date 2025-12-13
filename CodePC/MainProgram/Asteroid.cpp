#include "Asteroid.h"
#include "VectorUtility.h"
#include <iostream>

void Asteroid::update()
{
	Movement();
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float radius)
	: Entity(startPosition, sf::Color::White, radius)
{
	this->sphereShape.setOrigin(radius / 2, radius / 2);

	this->targetPosition = targetPosition;
	this->targetDirection = VectorUtility::getDirectionNormalize(this->targetPosition, getPosition());
}

void Asteroid::Movement()
{
	this->move(targetDirection);
}
