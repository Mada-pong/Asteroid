#include "AsteroidGameScene.h"

AsteroidGameScene::AsteroidGameScene(int width, int height)
	: Scene(width, height)
{
}

void AsteroidGameScene::update(float deltaTime)
{
	player.update(deltaTime);
	asteroidSpawner->update(deltaTime);

	collision.CheckCollision(groupA, asteroidSpawner->getObjectPtrs());
	collision.CheckCollision(player.getSpawner().getObjectPtrs(), asteroidSpawner->getObjectPtrs());

	if (player.getHealthComponent().getHealth() <= 0)
	{
		changeTransition();
	}
}

void AsteroidGameScene::draw(sf::RenderWindow& window)
{
	window.draw(this->player);
	window.draw(*this->asteroidSpawner);
}

sceneID AsteroidGameScene::changeTransition()
{
	return sceneID::GAMEOVER;
}
