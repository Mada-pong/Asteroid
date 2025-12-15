#pragma once
class HealthComponent
{
private: 
	int health;
	int maxHealth;
	bool isDead = false;

public: 
	HealthComponent(int health);
	HealthComponent(int health, int maxHealth);

	int getHealth() const;
	int getMaxHealth() const; 

	void setHealth(int newHealth);
	void addHealth(int health); 

	bool checkIfDead();
};

