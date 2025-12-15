#include "HealthComponent.h"

HealthComponent::HealthComponent(int health) : 
	health(health), maxHealth(health)
{
}

HealthComponent::HealthComponent(int health, int maxHealth)
	: health(health), maxHealth(maxHealth)
{
}

int HealthComponent::getHealth() const
{
	return this->health;
}

int HealthComponent::getMaxHealth() const
{
	return this->maxHealth;
}

void HealthComponent::setHealth(int newHealth)
{
	this->health = newHealth;
	this->maxHealth = newHealth;
}

/// <summary>
/// Add health on top of the current health. 
/// In practice it is the same as getHealth() + added health.
/// </summary>
/// <param name="health"></param>
void HealthComponent::addHealth(int health)
{
	this->health += health;

	if (this->health >= maxHealth)
	{
		this->health = maxHealth;
	}
}

bool HealthComponent::checkIfDead()
{
	if (this->health <= 0)
		return true;

	return false;
}
