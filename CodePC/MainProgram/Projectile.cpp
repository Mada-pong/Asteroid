#include "Projectile.h"
#include "PrintDebug.h"


Projectile::Projectile(sf::Vector2f startPosition, sf::Color color, float radius, float angle, float velocity, float timeToLive)
	: Entity(startPosition, color, radius), timeToLiveCooldown(timeToLive), velocity(velocity)
{
	direction = VectorUtility::getVectorByDegrees(angle);
	direction = VectorUtility::normalizeVector(direction);

	this->sphereShape.setOrigin(sf::Vector2f(radius, radius));

	timeToLiveCooldown.setOnFinished([this]() { markedForRemoval = true; });
	timeToLiveCooldown.start();
}

void Projectile::onHit()
{
	PrintDebug::Print("Projectile hit something!");
}

void Projectile::update(float deltaTime)
{
	move(direction * velocity);
}
