#include "AsteroidSpawner.h"

AsteroidSpawner::AsteroidSpawner(float xWidth, float yHeight, float spawnRate)
	: outsideBorderRadius(xWidth / 2), centerPosition(xWidth / 2.0f, yHeight / 2.0f)
{
	xMin = 0; 
	xMax = xWidth;

	yMin = 0; 
	yMax = yHeight;

	cooldown.setOnFinished([this]() { spawnOutsideBorder(); cooldown.start(); });
	cooldown.start();
}

AsteroidSpawner::~AsteroidSpawner()
{
}

void AsteroidSpawner::update(float deltaTime)
{
	for (size_t i = 0; i < this->asteroids.size(); i++)
	{
		asteroids[i].update();
	}

	cooldown.update(deltaTime);
}

void AsteroidSpawner::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < this->asteroids.size(); i++)
	{
		window.draw(asteroids[i]);
	}
}

void AsteroidSpawner::spawnAsteroid(sf::Vector2f spawnPosition)
{
	asteroids.emplace_back(spawnPosition, centerPosition, sf::Color::White, 10);
}

void AsteroidSpawner::spawnOutsideBorder()
{
	sf::Vector2f randomVector = VectorUtility::randomUnitVector() * float(outsideBorderRadius);
	spawnAsteroid(centerPosition + randomVector);
}

void AsteroidSpawner::setSpawnRate()
{
}

void AsteroidSpawner::setBoundary(float xMin, float xMax, float yMin, float yMax)
{
	this->xMin = xMin;
	this->xMax = xMax;

	this->yMin = yMin;
	this->yMax = yMax;
}

void AsteroidSpawner::setIsSpawning(bool isSpawning)
{
	this->isSpawning = isSpawning;
}
