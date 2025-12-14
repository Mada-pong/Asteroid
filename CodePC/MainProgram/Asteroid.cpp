#include "Asteroid.h"
#include "VectorUtility.h"
#include <iostream>

void Asteroid::update()
{
	Movement();
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float size, sf::Vector2f screenBorder)
	: Entity(startPosition, sf::Color::White, size), screenBorder(screenBorder)
{
	this->sphereShape.setOrigin(size / 2, size / 2);

	this->targetPosition = targetPosition;
	this->targetDirection = VectorUtility::getDirectionNormalize(this->targetPosition, getPosition());
}

bool Asteroid::isOutside() const
{
	if (getPosition().y < 0 + borderOffset.y || screenBorder.y - borderOffset.y < getPosition().y)
		return true;

	if (getPosition().x < 0 + borderOffset.x || screenBorder.x - borderOffset.x < getPosition().x)
		return true;

	return false;
}

void Asteroid::Movement()
{
	this->move(targetDirection);
}
