#include "ProjectileSpawner.h"
#include "PrintDebug.h"

ProjectileSpawner::ProjectileSpawner(float reloadDuration)
	: Spawner(reloadDuration)
{
	spawnCooldown.setOnFinished([this]() { canShoot = true; });
	PrintDebug::Print(spawnCooldown.getTime());
}

void ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition)
{
	spawnObject(spawnPosition, 90, 1);
}

void ProjectileSpawner::spawnObject(sf::Vector2f spawnPosition, float angle, float velocity)
{
	if (canShoot)
	{
		objects.emplace_back(spawnPosition, sf::Color::Yellow, 4.0f, angle, velocity, timeToLive);
		canShoot = false;
		spawnCooldown.start();
	}
}
