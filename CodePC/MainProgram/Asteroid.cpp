#include "Asteroid.h"
#include "PrintDebug.h"

void Asteroid::update(float deltaTime)
{
	this->move(targetDirection * baseSpeed);
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float radius, float speed, sf::Vector2f screenBorder)
	: Entity(startPosition, sf::Color::White, radius), screenBorder(screenBorder), healthComponent(baseHP),
	baseSpeed(speed)
{
	this->sphereShape.setOrigin(radius, radius);

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

void Asteroid::onDamage(int damage)
{
	healthComponent.reduceHealth(damage);
}

void Asteroid::onHit()
{
	PrintDebug::Print("Asteroid has been hit");
	healthComponent.reduceHealth(1);

	if (healthComponent.getHealth() <= 0)
		this->setMarkedForRemoval();
}
