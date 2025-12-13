#include "Entity.h"
#include <iostream>

Entity::Entity()
{
}

Entity::Entity(sf::Vector2f startPosition, sf::Color color, float radius)
	: sphereShape(radius)
{
	this->sphereShape.setFillColor(color);
	setPosition(startPosition);
}

void Entity::setPosition(sf::Vector2f position)
{
	this->vector2 = position;
	this->sphereShape.setPosition(vector2);
}

void Entity::move(sf::Vector2f vector)
{
	this->vector2 = vector;
	this->sphereShape.move(vector2);
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
