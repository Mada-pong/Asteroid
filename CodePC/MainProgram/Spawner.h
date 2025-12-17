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
protected: 
	std::vector<T> objects;
	std::vector<ICollision*> ptrViewer;

	bool isSpawning;

	Cooldown spawnCooldown;

	void populatePtrViewer(std::vector<T>& objects, std::vector<ICollision*>& out)
	{
		out.clear();
		out.reserve(objects.size());

		for (size_t i = 0; i < objects.size(); i++)
		{
			out.push_back(&objects[i]);
		}
	}
public:
	Spawner(float spawnRate): spawnCooldown(spawnRate){}

	~Spawner() = default;

	virtual void spawnObject(sf::Vector2f spawnPosition) = 0;

	virtual void setSpawnRate(float duration)
	{
		this->spawnCooldown.setNewTime(duration);
	}

	virtual void setIsSpawning(bool isSpawning)
	{
		this->isSpawning = isSpawning;
	}

	virtual std::vector<ICollision*>& getObjectPtrs()
	{
		populatePtrViewer(objects, ptrViewer);

		return this->ptrViewer;
	}

	virtual void update(float deltaTime)
	{
		spawnCooldown.update(deltaTime);

		for (size_t i = 0; i < this->objects.size(); i++)
		{
			objects[i].update();
		}
	}

	virtual void draw(sf::RenderWindow& window)
	{
		for (size_t i = 0; i < this->objects.size(); i++)
		{
			window.draw(objects[i]);
		}
	}
};

#endif // !SPAWNER_HPP
