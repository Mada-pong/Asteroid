#ifndef PROJECTILESPAWNER_HPP
#define PROJECTILESPAWNER_HPP

#include "Spawner.h"
#include "Projectile.h"

class ProjectileSpawner : public Spawner<Projectile>
{
private: 
	float timeToLive = 0.5f;
	bool canShoot = true;

	// Inherited via Spawner
	Projectile* spawnObject(sf::Vector2f spawnPosition) override;
public:
	ProjectileSpawner(float reloadDuration);
	~ProjectileSpawner() = default;

	Projectile* spawnObject(sf::Vector2f spawnPosition, float angle, float velocity);
};

#endif // !PROJECTILESPAWNER_HPP
