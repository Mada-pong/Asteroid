#include "AsteroidGameScene.h"

AsteroidGameScene::AsteroidGameScene(int width, int height, int* score)
	: Scene(width, height), score(score)
{
	asteroidSpawner->getCooldown().setOnFinished([this]() {
		asteroidSetup();
		});

	asteroidSpawner->getCooldown().start();
}

void AsteroidGameScene::update(float deltaTime)
{
	player.update(deltaTime);
	asteroidSpawner->update(deltaTime);

	collision.CheckCollision(playerGroup, asteroidSpawner->getObjectPtrs());
	collision.CheckCollision(player.getSpawner().getObjectPtrs(), asteroidSpawner->getObjectPtrs());

	if (player.getHealthComponent().getHealth() <= 0)
	{
		this->hasPendingTransition = true;
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

void AsteroidGameScene::asteroidSetup()
{
	Asteroid* asteroidPtr = asteroidSpawner->spawnOutsideBorder();

	asteroidPtr->setOnDied([this](int) {
		*this->score += 10;
		});

	asteroidSpawner->spawnCooldown.start();
}

void AsteroidGameScene::onEnterScene()
{
}
