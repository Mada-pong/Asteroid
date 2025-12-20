#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "AsteroidSpawner.h"
#include "CollisionSystem.h"
#include <vector>
#include "Projectile.h"
#include "ProjectileSpawner.h"
#include "Scene.h"
#include "AsteroidGameScene.h"
#include "SceneID.h"

class AsteroidGame
{
private:
	static const int WIDTH = 900; 
	static const int HEIGHT = 600;
private: 
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	AsteroidGameScene* asteroidGame = new AsteroidGameScene(WIDTH, HEIGHT);
	Scene* currentScene = asteroidGame;

	CollisionSystem collision;

	Player player = Player(sf::Vector2f(100, 100), sf::Color::Red, 5, sf::Vector2f(WIDTH, HEIGHT));
	std::vector<ICollision*> groupA{&player};

	std::unique_ptr<AsteroidSpawner> asteroidSpawner = std::make_unique<AsteroidSpawner>(WIDTH, HEIGHT, 5);

	void handleEvents();
	void update();
	void render();
	void switchScene(sceneID id);
public: 
	AsteroidGame();
	~AsteroidGame();
	void run();
};

