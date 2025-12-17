#include "Spawner.h"

template<typename T>
Spawner<T>::Spawner(float spawnRate)
	: spawnCooldown(spawnRate)
{
}

template<typename T>
void Spawner<T>::setSpawnRate(float duration)
{
	this->spawnCooldown.setNewTime(duration);
}

template<typename T>
void Spawner<T>::setIsSpawning(bool isSpawning)
{
	this->isSpawning = isSpawning;
}

template<typename T>
std::vector<ICollision*>& Spawner<T>::getObjectPtrs()
{
	return this->ptrViewer;
}

template<typename T>
void Spawner<T>::update(float deltaTime)
{
	for (size_t i = 0; i < this->objects.size(); i++)
	{
		objects[i].update();
	}
}

template<typename T>
void Spawner<T>::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < this->objects.size(); i++)
	{
		window.draw(objects[i]);
	}
}

template<typename T>
void Spawner<T>::populatePtrViewer(std::vector<T>& objects, std::vector<ICollision*>& out)
{
	out.clear();
	out.reserve(objects.size());

	for (size_t i = 0; i < objects.size(); i++)
	{
		out.push_back(&objects[i]);
	}
}