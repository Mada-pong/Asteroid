#ifndef ASTEROIDSPAWNER_HPP
#define ASTEROIDSPAWNER_HPP

#include <vector>
#include "Entity.h"
#include "Asteroid.h"
#include <SFML/Graphics.hpp>

class AsteroidSpawner
{
private: 
	int xMin, xMax, yMin, yMax;
	int outsideBorderRadius;

	sf::Vector2f centerPosition;
	std::vector<Asteroid> asteroids;
	bool isSpawning = false;

public:
	AsteroidSpawner(int xWidth, int yHeight, float spawnRate);
	~AsteroidSpawner();

	void spawnAsteroid(sf::Vector2f spawnPosition);
	void spawnOutsideBorder();


	void setSpawnRate();
	void setBoundary(int xMin, int xMax, int yMin, int yMax);

	void setIsSpawning(bool isSpawning);

	void update();
	void draw(sf::RenderWindow& window);
};

#endif // !ASTEROIDSPAWNER_HPP
