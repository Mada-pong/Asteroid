#include "Player.h"

void Player::update()
{
	Input();
}

Player::Player(sf::Vector2f startPosition, sf::Color color, float radius)
	: Entity(startPosition, color, radius)
{
	this->setScale(sf::Vector2f(0.7f, 2));
	this->sphereShape.setOrigin(sf::Vector2f((radius / 2) * 0.7f, (radius / 2) * 2));
}


void Player::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		Turn(-baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Turn(-baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Turn(baseRotationSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sf::Vector2f dir = VectorUtility::getVectorByDegrees(this->sphereShape.getRotation() - this->rotationOffset);

		Forward(dir * baseSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sf::Vector2f dir = VectorUtility::getVectorByDegrees(this->sphereShape.getRotation() - this->rotationOffset);

		Forward(dir * -baseSpeed);
	}
}

void Player::Forward(sf::Vector2f vector)
{
	this->move(vector);
}

void Player::Side(float speed)
{
	this->move(sf::Vector2f(speed, 0));
}

void Player::Turn(float turnRate)
{
	this->sphereShape.rotate(turnRate);
}

/// <summary>
/// Collision on hit code
/// </summary>
void Player::onHit(int damage)
{

}