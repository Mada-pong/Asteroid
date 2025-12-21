#include "HealthComponent.h"

HealthComponent::HealthComponent(int health) : 
	health(health), maxHealth(health)
{
}

HealthComponent::HealthComponent(int health, int maxHealth)
	: health(health), maxHealth(maxHealth)
{
}

/// Get current health
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

/// Add health on top of the current health. 
/// In practice it is the same as getHealth() + added health.
void HealthComponent::addHealth(int health)
{
	this->health += health;

	if (this->health >= maxHealth)
	{
		this->health = maxHealth;
	}
}

void HealthComponent::reduceHealth(int health)
{
	this->health -= health;
}

bool HealthComponent::checkIfDead()
{
	if (this->health <= 0)
		return true;

	return false;
}
