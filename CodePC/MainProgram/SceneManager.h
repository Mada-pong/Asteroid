#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "AsteroidGameScene.h"
#include "GameOverScene.h"
#include "SceneID.h"
#include <map>
#include "PrintDebug.h"

class SceneManager
{
private:
	static const int WIDTH = 900; 
	static const int HEIGHT = 600;

	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	int score;

	std::map<sceneID, Scene*> sceneMap = { 
		{ sceneID::ASTEROIDGAME, new AsteroidGameScene(WIDTH, HEIGHT, &score) },
		{ sceneID::GAMEOVER, new GameOverScene(WIDTH, HEIGHT, &score)}
	};

	Scene* currentScene = sceneMap[sceneID::ASTEROIDGAME];

	void handleEvents();
	void update();
	void render();
	void switchScene(sceneID id);
public: 
	SceneManager();
	~SceneManager();
	void run();
};

#endif