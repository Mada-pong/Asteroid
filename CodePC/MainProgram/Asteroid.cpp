#include "Asteroid.h"
#include "VectorUtility.h"
#include "PrintDebug.h"

void Asteroid::update()
{
	Movement();
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float size, sf::Vector2f screenBorder)
	: Entity(startPosition, sf::Color::White, size), screenBorder(screenBorder), healthComponent(baseHP)
{
	this->sphereShape.setOrigin(size / 2, size / 2);

	this->targetPosition = targetPosition;
	this->targetDirection = VectorUtility::getDirectionNormalize(this->targetPosition, getPosition());
}

///TODO: Redo this to change toRemoval = true
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

void Asteroid::onDamage(int damage)
{
	healthComponent.reduceHealth(damage);
}

void Asteroid::onHit()
{
	PrintDebug::Print("Asteroid has been hit");
	healthComponent.reduceHealth(1);

	this->markedForRemoval = true;
}
