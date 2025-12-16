#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.h"
#include "HealthComponent.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
private: 
	float baseSpeed = 5;
	float baseRotationSpeed = 10;
	float rotationOffset = 90;

	float health = 3;

	HealthComponent healthComponent;

	void Input();

	void Forward(sf::Vector2f vector); 
	void Side(float speed);
	void Turn(float turnRadius);
public: 
	// Inherited via Entity
	void update() override;
	Player(sf::Vector2f startPosition, sf::Color color, float radius);

	void onDamage(int damage) override;
};

#endif // !PLAYER_HPP