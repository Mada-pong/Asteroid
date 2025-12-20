#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "AsteroidSpawner.h"
#include "CollisionSystem.h"
#include <vector>
#include "Projectile.h"
#include "ProjectileSpawner.h"
#include "Player.h"

class AsteroidGameScene : public Scene
{

public:
	AsteroidGameScene(int width, int height);

	// Inherited via Scene
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
private:
	CollisionSystem collision;

	Player player = Player(sf::Vector2f(100, 100), sf::Color::Red, 5, sf::Vector2f(WIDTH, HEIGHT));
	std::vector<ICollision*> groupA{ &player };

	std::unique_ptr<AsteroidSpawner> asteroidSpawner = std::make_unique<AsteroidSpawner>(WIDTH, HEIGHT, 5);

	// Inherited via Scene
	sceneID changeTransition() override;
};

