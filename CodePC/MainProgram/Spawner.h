#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"
#include "Asteroid.h"
#include "Projectile.h"

template <typename T>
class Spawner
{
private: 
	std::vector<T> objects;
	std::vector<ICollision*> ptrViewer;

	bool isSpawning;

	Cooldown spawnCooldown;

	void populatePtrViewer(std::vector<T>& objects, std::vector<ICollision*>& out);
public:
	Spawner(float spawnRate);
	~Spawner() = default;

	virtual void SpawnObject(sf::Vector2f spawnPosition) = 0;

	void setSpawnRate(float duration);
	void setIsSpawning(bool isSpawning);

	std::vector<ICollision*>& getObjectPtrs();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

#endif // !SPAWNER_HPP
