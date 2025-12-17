#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "AsteroidSpawner.h"
#include "CollisionSystem.h"
#include <vector>
#include "Projectile.h"

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

	CollisionSystem collision;

	Player player = Player(sf::Vector2f(100, 100), sf::Color::Red, 5);
	std::vector<ICollision*> groupA{&player};

	Projectile testProjectile = Projectile(sf::Vector2f(400, 100), sf::Color::Yellow, 5, 0, 5.0f, 1.0f);

	std::unique_ptr<AsteroidSpawner> spawner = std::make_unique<AsteroidSpawner>(WIDTH, HEIGHT, 5);;

	void handleEvents();
	void update();
	void render();

	void objectCleanup();
public: 
	AsteroidGame();
	~AsteroidGame();
	void run();
};

