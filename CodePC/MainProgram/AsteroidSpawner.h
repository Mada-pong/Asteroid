#ifndef ASTEROIDSPAWNER_HPP
#define ASTEROIDSPAWNER_HPP

#include <vector>
#include "Entity.h"
#include "Asteroid.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"

class AsteroidSpawner
{
private: 
	float xMin, xMax, yMin, yMax;
	float outsideBorderRadius;
	float removalRadius;

	sf::Vector2f centerPosition;
	std::vector<Asteroid> asteroids;
	std::vector<ICollision*> asteroidPtrViewer;

	bool isSpawning = true;

	Cooldown cooldown = Cooldown(5.0f);

	void populatePtrViewer(std::vector<Asteroid>& asteroids, std::vector<ICollision*>& out);
public:
	AsteroidSpawner(float xWidth, float yHeight, float spawnRate);
	~AsteroidSpawner();

	void spawnAsteroid(sf::Vector2f spawnPosition);
	void spawnOutsideBorder();

	void setSpawnRate();
	void setBoundary(float xMin, float xMax, float yMin, float yMax);

	void setIsSpawning(bool isSpawning);

	std::vector<ICollision*>& getAsteroidsPtrs();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

#endif // !ASTEROIDSPAWNER_HPP
