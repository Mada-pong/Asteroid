#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Cooldown.h"
#include "Asteroid.h"
#include "Projectile.h"
#include <functional>

template <typename T>
class Spawner : public sf::Drawable
{
protected: 
	std::vector<std::unique_ptr<T>> objects;
	std::vector<ICollision*> ptrViewer;

	bool isSpawning = false;

	/// <summary>
	/// Clear and create a new vector list with the pointers ICollisions from objects.
	/// Output the pointer viewer through reference out. 
	/// </summary>
	/// <param name="objects">std::vector<std::unique_ptr<T>>&</param>
	/// <param name="out">std::vector<ICollision*>&</param>
	void populatePtrViewer(std::vector<std::unique_ptr<T>>& objects, std::vector<ICollision*>& out)
	{
		out.clear();
		out.reserve(objects.size());

		for (size_t i = 0; i < objects.size(); i++)
		{
			out.push_back(objects[i].get());
		}
	}

	/// <summary>
	/// Check if the object is marked for removal and then erase it from the list.
	/// </summary>
	void removedMarkedForRemovalObjects()
	{
		for (size_t i = 0; i < objects.size(); i++)
		{
			if (objects[i]->isMarkedForRemoval())
			{
				objects.erase(objects.begin() + i);
			}
		}
	}

public:
	Cooldown spawnCooldown;

	Spawner(float spawnRate): spawnCooldown(spawnRate){}

	virtual ~Spawner() = default;

	virtual Cooldown& getCooldown() { return this->spawnCooldown; }

	virtual T* spawnObject(sf::Vector2f spawnPosition) = 0;

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
			objects[i]->update(deltaTime);
		}

		removedMarkedForRemovalObjects();
	}

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for (size_t i = 0; i < this->objects.size(); i++)
		{
			target.draw(*objects[i]);
		}
	}
};

#endif
