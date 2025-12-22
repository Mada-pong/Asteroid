#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height)
	: Scene(width, height)
{
	font.loadFromFile("../Font/arial.ttf");

	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER!");
	gameOverText.setCharacterSize(32);
	gameOverText.setFillColor(sf::Color::White);

	sf::FloatRect b = gameOverText.getLocalBounds();
	gameOverText.setOrigin(b.left + b.width * 0.5f, b.top + b.height * 0.5f);

	gameOverText.setPosition(width / 2, height / 2);
}

void GameOverScene::update(float deltaTime)
{
}

void GameOverScene::draw(sf::RenderWindow& window)
{
	window.draw(gameOverText);
}

sceneID GameOverScene::changeTransition()
{
	return sceneID();
}
