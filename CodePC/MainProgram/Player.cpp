#include "Player.h"
#include "PrintDebug.h"

Player::Player(sf::Vector2f startPosition, sf::Color color, float radius, sf::Vector2f border)
	: Entity(startPosition, color, radius), healthComponent(health), projectileSpawner(fireRate), screenBorder(border), IFrameCooldown(iFrameDuration)
{
	this->setScale(sf::Vector2f(0.7f, 2));
	this->sphereShape.setOrigin(sf::Vector2f((radius / 2) * 0.7f, (radius / 2) * 2));

	IFrameCooldown.setOnFinished([this]() { this->isInvincible = false; });
}

void Player::update(float deltaTime)
{
	borderWrap();
	Input();

	IFrameCooldown.update(deltaTime);
	projectileSpawner.update(deltaTime);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);

	projectileSpawner.draw(target, states);
}

void Player::borderWrap()
{
	if (getPosition().y < 0 - borderOffset)
	{
		setPosition(sf::Vector2f(getPosition().x, screenBorder.y));
	}

	if (screenBorder.y + borderOffset < getPosition().y)
	{
		setPosition(sf::Vector2f(getPosition().x, 0));
	}

	if (getPosition().x < 0 - borderOffset)
	{
		setPosition(sf::Vector2f(screenBorder.x, getPosition().y));
	}

	if (screenBorder.x + borderOffset < getPosition().x)
	{
		setPosition(sf::Vector2f(0, getPosition().y));
	}
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		projectileSpawner.spawnObject(this->getPosition(), this->sphereShape.getRotation() - this->rotationOffset, 10);
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

void Player::onHit()
{
	if (!this->isInvincible)
	{
		healthComponent.reduceHealth(1);
		this->isInvincible = true;
		IFrameCooldown.start();
	}

	PrintDebug::Print("Player HP: ");
	PrintDebug::Print(healthComponent.getHealth());

	if (healthComponent.checkIfDead())
	{
		setMarkedForRemoval();
	}
}
