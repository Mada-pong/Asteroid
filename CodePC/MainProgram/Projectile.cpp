#include "Projectile.h"


Projectile::Projectile(sf::Vector2f startPosition, sf::Color color, float radius, float angle, float velocity, float timeToLive)
	: Entity(startPosition, color, radius), timeToLiveCooldown(timeToLive), velocity(velocity)
{
	direction = VectorUtility::getVectorByDegrees(angle);
	direction = VectorUtility::normalizeVector(direction);

	timeToLiveCooldown.setOnFinished([this]() { markedForRemoval = true; });
	timeToLiveCooldown.start();
}

void Projectile::update()
{
	move(direction * velocity);
}
