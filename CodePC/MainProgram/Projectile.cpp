#include "Projectile.h"
#include "PrintDebug.h"

Projectile::Projectile(sf::Vector2f startPosition, sf::Color color, float radius, float angle, float velocity, float timeToLive)
	: Entity(startPosition, color, radius), timeToLiveCooldown(timeToLive), velocity(velocity)
{
	direction = VectorUtility::getVectorByDegrees(angle);
	direction = VectorUtility::normalizeVector(direction);

	this->getSphereShape().setOrigin(sf::Vector2f(radius, radius));

	timeToLiveCooldown.setOnFinished([this]() { setMarkedForRemoval(); });
	timeToLiveCooldown.start();
}

void Projectile::update(float deltaTime)
{
	timeToLiveCooldown.update(deltaTime);
	move(direction * velocity);
}

void Projectile::onHit()
{
	PrintDebug::Print("Projectile hit something!");
	this->setMarkedForRemoval();
}

