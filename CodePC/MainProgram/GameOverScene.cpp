#include "GameOverScene.h"
#include "PrintDebug.h"

GameOverScene::GameOverScene(int width, int height, int* score)
	: Scene(width, height), score(score)
{
	font.loadFromFile("../Font/arial.ttf");

	displayText(gameOverText, "GAME OVER!");
	gameOverText.setPosition(width / 2, height / 2);

	displayText(scoreText, std::to_string(*this->score));
	scoreText.setPosition(width / 2, height / 2 + 30);
}

void GameOverScene::displayText(sf::Text& textObject, std::string displayedText)
{
	textObject.setFont(font);
	textObject.setString(displayedText);
	textObject.setCharacterSize(32);
	textObject.setFillColor(sf::Color::White);

	sf::FloatRect b = textObject.getLocalBounds();
	textObject.setOrigin(b.left + b.width * 0.5f, b.top + b.height * 0.5f);
}

void GameOverScene::saveScoreToFile()
{
	std::ofstream file("../score.txt", std::ios_base::app);

	auto now = std::chrono::system_clock::now();
	std::string formattedTime = std::format("{:%Y-%m-%d %H:%M:%S}", now);

	file << "Time: " << formattedTime << " - Score: " << std::to_string(*this->score) << std::endl;

	file.close();
}

void GameOverScene::onEnterScene()
{
	scoreText.setString(std::to_string(*this->score));
	saveScoreToFile();
}

void GameOverScene::update(float deltaTime)
{
}

void GameOverScene::draw(sf::RenderWindow& window)
{
	window.draw(gameOverText);
	window.draw(scoreText);
}

sceneID GameOverScene::changeTransition()
{
	return sceneID();
}
