#ifndef ASTEROIDGAMESCENE_HPP
#define ASTEROIDGAMESCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "AsteroidSpawner.h"
#include "CollisionSystem.h"
#include "Projectile.h"
#include "ProjectileSpawner.h"
#include "Player.h"

class AsteroidGameScene : public Scene
{
public:
	AsteroidGameScene(int width, int height, int& score);
	~AsteroidGameScene() = default;

	// Inherited via Scene
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
private:
	float asteroidSpawnRate = 0.5f;

	// General player stats
	sf::Vector2f playerStartPosition = sf::Vector2f(100, 100);
	sf::Vector2f playerBorderLimit = sf::Vector2f(WIDTH, HEIGHT);
	sf::Color playerColor = sf::Color::Red;
	float playerSize = 5;

	int& score;

	CollisionSystem collision;

	Player player = Player(playerStartPosition, playerColor, playerSize, playerBorderLimit);
	std::vector<ICollision*> playerGroup{ &player };

	std::unique_ptr<AsteroidSpawner> asteroidSpawner = std::make_unique<AsteroidSpawner>(WIDTH, HEIGHT, asteroidSpawnRate);

	// Inherited via Scene
	sceneID changeTransition() override;
	void asteroidSetup();

	// Inherited via Scene
	void onEnterScene() override;
};

#endif // !1
