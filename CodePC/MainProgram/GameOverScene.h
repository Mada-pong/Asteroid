#ifndef GAMEOVERSCENE_HPP
#define GAMEOVERSCENE_HPP

#include "Scene.h"
#include <fstream>
#include <chrono>
#include <format>


class GameOverScene : public Scene
{
public:
	GameOverScene(int width, int height, int* score);
	~GameOverScene() = default;

	// Inherited via Scene
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private: 
	sceneID changeTransition() override;
	void displayText(sf::Text & textObject, std::string displayedText);
	void saveScoreToFile();

	int* score;

	sf::Font font;
	sf::Text gameOverText;
	sf::Text scoreText;

	// Inherited via Scene
	void onEnterScene() override;
};

#endif // !GAMEOVERSCENE_HPP
