#include "AsteroidSpawner.h"
#include "Spawner.h"

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

void AsteroidSpawner::spawnObject(sf::Vector2f spawnPosition)
{
	objects.emplace_back(spawnPosition, centerPosition, sf::Color::White, 40, 1, sf::Vector2f(xMax, yMax));
}

void AsteroidSpawner::update(float deltaTime)
{
	Spawner::update(deltaTime);

	///TODO: Move the eraser code to a cleanup code
	objects.erase(std::remove_if(objects.begin(), objects.end(), [](const Asteroid& asteroid)
		{
			return asteroid.isOutside();
		}),
		objects.end());
}

void AsteroidSpawner::spawnOutsideBorder()
{
	//sf::Vector2f randomVector = VectorUtility::randomUnitVector() * float(outsideBorderRadius);
	sf::Vector2f randomVector = VectorUtility::randomUnitVector() * float(400);
	spawnObject(centerPosition + randomVector);
}

void AsteroidSpawner::setBoundary(float xMin, float xMax, float yMin, float yMax)
{
	this->xMin = xMin;
	this->xMax = xMax;

	this->yMin = yMin;
	this->yMax = yMax;
}

