#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height)
	: Scene(width, height)
{
}

void GameOverScene::update(float deltaTime)
{
}

void GameOverScene::draw(sf::RenderWindow& window)
{
}

sceneID GameOverScene::changeTransition()
{
	return sceneID();
}
