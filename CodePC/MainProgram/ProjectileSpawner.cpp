#include "ProjectileSpawner.h"
#include "PrintDebug.h"

ProjectileSpawner::ProjectileSpawner(float reloadDuration)
	: Spawner(reloadDuration)
{
	getCooldown().setOnFinished([this]() { canShoot = true; });
}

Projectile* ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition)
{
	spawnObject(spawnPosition, 90, 1);

	return getObjects().back().get();
}

Projectile* ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition, float angle, float velocity)
{
	getObjects().emplace_back(std::make_unique<Projectile>(spawnPosition, sf::Color::Yellow, 4.0f, angle, velocity, timeToLive));

	return getObjects().back().get();
}
