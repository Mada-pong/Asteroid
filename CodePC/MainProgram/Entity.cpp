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
	this->position = position;
	this->sphereShape.setPosition(position);
}

void Entity::move(sf::Vector2f delta)
{
	this->position += delta;
	this->sphereShape.setPosition(position);
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
