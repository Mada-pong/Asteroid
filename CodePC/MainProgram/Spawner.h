#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"

template <typename T>
class Spawner
{
private: 
	std::vector<T> objects;
	std::vector<ICollision*> PtrViewer;

	bool isSpawning;

	Cooldown spawnCooldown;

	void populatePtrViewer(std::vector<T>& objects, std::vector<ICollision*>& out);
public:
	Spawner(float spawnRate);
	~Spawner() = default;

	void SpawnObject(sf::Vector2f spawnPosition);

	void setSpawnRate();
	void setIsSpawning(bool isSpawning);

	std::vector<ICollision*>& getObjectPtrs();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

#endif // !SPAWNER_HPP
