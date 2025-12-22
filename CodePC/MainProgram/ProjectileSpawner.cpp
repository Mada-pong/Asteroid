#include "ProjectileSpawner.h"
#include "PrintDebug.h"

ProjectileSpawner::ProjectileSpawner(float reloadDuration)
	: Spawner(reloadDuration)
{
	spawnCooldown.setOnFinished([this]() { canShoot = true; });
}

Projectile* ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition)
{
	spawnObject(spawnPosition, 90, 1);

	return objects.back().get();
}

///TODO: Change so that this doesn't 
Projectile* ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition, float angle, float velocity)
{
	if (!canShoot)
		return;

	objects.emplace_back(std::make_unique<Projectile>(spawnPosition, sf::Color::Yellow, 4.0f, angle, velocity, timeToLive));
	canShoot = false;
	spawnCooldown.start();

	return objects.back().get();
}
