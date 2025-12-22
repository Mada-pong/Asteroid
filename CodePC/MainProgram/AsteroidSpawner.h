#ifndef ASTEROIDSPAWNER_HPP
#define ASTEROIDSPAWNER_HPP

#include <vector>
#include "Entity.h"
#include "Asteroid.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"
#include "Spawner.h"
#include <functional>

class AsteroidSpawner : public Spawner<Asteroid>
{
private: 
	float xMin, xMax, yMin, yMax;
	float outsideBorderRadius;
	float removalRadius = 1000;

	sf::Vector2f centerPosition;
public:
	AsteroidSpawner(float xWidth, float yHeight, float spawnRate);
	~AsteroidSpawner() = default;

	void spawnOutsideBorder();
	void setBoundary(float xMin, float xMax, float yMin, float yMax);

	Asteroid* spawnObject(sf::Vector2f spawnPosition) override;
	void update(float deltaTime) override;
};

#endif // !ASTEROIDSPAWNER_HPP
