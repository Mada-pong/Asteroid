#include "Player.h"
#include <iostream>


void Player::update()
{
	Input();
}

Player::Player(sf::Vector2f startPosition, sf::Color color, float radius)
	: Entity(startPosition.x, startPosition.y, color, radius)
{
	this->setScale(sf::Vector2f(0.7f, 2));
}

void Player::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Turn(-baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Turn(-baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Turn(baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Forward(baseSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Forward(-baseSpeed);
	}
}

void Player::Forward(float speed)
{
	this->move(sf::Vector2f(0, -speed));
}

void Player::Side(float speed)
{
	this->move(sf::Vector2f(speed, 0));
}

void Player::Turn(float turnRate)
{
	sphereShape.rotate(sf::degree)
}

