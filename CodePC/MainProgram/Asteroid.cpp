#include "Asteroid.h"

void Asteroid::update()
{
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f centerPosition, sf::Color color, float radius)
	: Entity(startPosition.x, startPosition.y, sf::Color::White, radius)
{
	this->sphereShape.setOrigin(radius / 2, radius / 2);
}

void Asteroid::Move()
{
}
