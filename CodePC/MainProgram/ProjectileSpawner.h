#ifndef PROJECTILESPAWNER_HPP
#define PROJECTILESPAWNER_HPP

#include "Spawner.h"
#include "Projectile.h"

class ProjectileSpawner : public Spawner<Projectile>
{
private: 
	float timeToLive = 5.0f;
	bool canShoot = true;

	// Inherited via Spawner
	void spawnObject(sf::Vector2f spawnPosition) override;
public:
	ProjectileSpawner(float reloadDuration);
	~ProjectileSpawner() = default;

	void spawnObject(sf::Vector2f spawnPosition, float angle, float velocity);
};

#endif // !PROJECTILESPAWNER_HPP
