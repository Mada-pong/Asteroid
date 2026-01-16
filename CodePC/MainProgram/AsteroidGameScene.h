#ifndef ASTEROIDGAMESCENE_HPP
#define ASTEROIDGAMESCENE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "AsteroidSpawner.h"
#include "CollisionSystem.h"
#include "Player.h"

class AsteroidGameScene : public Scene
{
public:
	AsteroidGameScene(int width, int height, int* score);

	// Inherited via Scene
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
private:
	int* score;
	float asteroidSpawnRate = 0.5f;

	// General player stats
	sf::Vector2f playerStartPosition = sf::Vector2f(getWidth() / 2, getHeight() / 2);
	sf::Vector2f borderLimit = sf::Vector2f(getWidth(), getHeight());
	sf::Color playerColor = sf::Color::Red;
	float playerSize = 5;

	CollisionSystem collision;

	Player player = Player(playerStartPosition, playerColor, playerSize, borderLimit);
	std::vector<ICollision*> playerGroup{ &player };

	std::unique_ptr<AsteroidSpawner> asteroidSpawner = std::make_unique<AsteroidSpawner>(getWidth(), getHeight(), asteroidSpawnRate);

	// Inherited via Scene
	sceneID changeTransition() override;
	void asteroidSetup();

	// Inherited via Scene
	void onEnterScene() override;
};

#endif
