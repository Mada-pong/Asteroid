#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(float windowWidth, float windowHeight, sf::Color color, float radius)
	: sphereShape(radius)
{
	this->sphereShape.setFillColor(color);
	this->sphereShape.setPosition(sf::Vector2f(windowWidth/2, windowHeight - (radius / 2)));
}

void Entity::setPosition(sf::Vector2f vector)
{
	this->sphereShape.setPosition(vector);
}

void Entity::move(sf::Vector2f vector)
{
	this->sphereShape.move(vector);
}

void Entity::setScale(sf::Vector2f vectorScale)
{
	this->scale = vectorScale;
	this->sphereShape.setScale(this->scale);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sphereShape);
}
