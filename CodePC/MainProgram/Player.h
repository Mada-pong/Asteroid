#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
private: 
	float baseSpeed = 5;
	float baseRotationSpeed = 1;

	void Input();

	void Forward(float speed); 
	void Side(float speed);
	void Turn(float turnRadius);
public: 
	// Inherited via Entity
	void update() override;
	Player(sf::Vector2f startPosition, sf::Color color, float radius);
};
