#include "AsteroidSpawner.h"

AsteroidSpawner::AsteroidSpawner(float xWidth, float yHeight, float spawnRate)
	: Spawner(spawnRate), outsideBorderRadius(xWidth / 2), centerPosition(xWidth / 2.0f, yHeight / 2.0f)
{
	xMin = 0; 
	xMax = xWidth;

	yMin = 0; 
	yMax = yHeight;

	spawnCooldown.setOnFinished([this]() { spawnOutsideBorder(); spawnCooldown.start(); });
	spawnCooldown.start();
}

void AsteroidSpawner::update(float deltaTime)
{
	Spawner::update(deltaTime);

	for (size_t i = 0; i < this->objects.size(); i++)
	{
		if (objects[i]->isOutside())
		{
			objects[i]->setMarkedForRemoval();
		}
	}
}

void AsteroidSpawner::AsteroidspawnObject(sf::Vector2f spawnPosition)
{
	objects.emplace_back(std::make_unique<Asteroid>(spawnPosition, centerPosition, sf::Color::White, 40, 1, sf::Vector2f(xMax, yMax)));
}

void AsteroidSpawner::spawnOutsideBorder()
{
	//sf::Vector2f randomVector = VectorUtility::randomUnitVector() * float(outsideBorderRadius);
	sf::Vector2f randomVector = VectorUtility::randomUnitVector() * float(200);
	AsteroidspawnObject(centerPosition + randomVector);
}

void AsteroidSpawner::setBoundary(float xMin, float xMax, float yMin, float yMax)
{
	this->xMin = xMin;
	this->xMax = xMax;

	this->yMin = yMin;
	this->yMax = yMax;
}

