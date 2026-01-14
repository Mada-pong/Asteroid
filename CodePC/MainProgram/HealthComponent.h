#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOMPONENT_HPP

class HealthComponent
{
private:
	int health;
	int maxHealth;
public:
	HealthComponent(int health);
	HealthComponent(int health, int maxHealth);

	int getHealth() const;
	int getMaxHealth() const;

	void setHealth(int newHealth);
	void addHealth(int health);
	void reduceHealth(int health);

	bool checkIfDead();
};

#endif // !HEALTHCOMPONENT_HPP
