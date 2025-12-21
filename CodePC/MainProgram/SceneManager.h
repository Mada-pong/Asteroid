#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "AsteroidGameScene.h"
#include "SceneID.h"
#include <map>

class SceneManager
{
private:
	static const int WIDTH = 900; 
	static const int HEIGHT = 600;
private: 
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	std::map<sceneID, Scene*> sceneMap = { 
		{ sceneID::ASTEROIDGAME, new AsteroidGameScene(WIDTH, HEIGHT) }
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

#endif // !SCENEMANAGER_HPP