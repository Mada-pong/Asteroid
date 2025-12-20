#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.h"
#include "HealthComponent.h"
#include <SFML/Graphics.hpp>
#include "ProjectileSpawner.h"

class Player : public Entity
{
private: 
	float baseSpeed = 5;
	float baseRotationSpeed = 10;
	float rotationOffset = 90;

	float health = 3;

	float fireRate = .1f;

	sf::Vector2f screenBorder;
	int borderOffset = 50;

	HealthComponent healthComponent;
	ProjectileSpawner projectileSpawner;

	void Input();

	void Forward(sf::Vector2f vector); 
	void Side(float speed);
	void Turn(float turnRadius);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void borderWrap();
public: 
	Player(sf::Vector2f startPosition, sf::Color color, float radius, sf::Vector2f border);

	// Inherited via Entity
	void update(float deltaTime) override;
	void onHit() override;

	ProjectileSpawner& getSpawner();
};

#endif // !PLAYER_HPP