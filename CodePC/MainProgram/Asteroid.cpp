#include "Asteroid.h"
#include "PrintDebug.h"
#include "VectorUtility.h"

void Asteroid::update(float deltaTime)
{
	this->move(targetDirection * baseSpeed);
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f targetPosition, sf::Color color, float radius, float speed, sf::Vector2f screenBorder)
	: Entity(startPosition, sf::Color::White, radius), screenBorder(screenBorder), healthComponent(baseHP),
	baseSpeed(speed)
{
	this->getSphereShape().setOrigin(radius, radius);

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

void Asteroid::onDamage(int damage)
{
	healthComponent.reduceHealth(damage);
}

void Asteroid::onHit()
{
	if (isMarkedForRemoval()) return;

	PrintDebug::Print("Asteroid has been hit");
	healthComponent.reduceHealth(1);

	if (healthComponent.getHealth() <= 0)
	{
		if (onDied) onDied(1);

		this->setMarkedForRemoval();
	}
}

void Asteroid::setOnDied(std::function<void(int)> function)
{
	onDied = std::move(function);
}
