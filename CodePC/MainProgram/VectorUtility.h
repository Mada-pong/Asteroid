#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <random>
#include <numbers>

class VectorUtility
{
private: 
	static const double PI;
public: 
	static double degreeToRad(double degrees);

	static sf::Vector2f getVectorByDegrees(float degrees);

	static sf::Vector2f getDirection(sf::Vector2f targetPosition, sf::Vector2f currentPosition);
	static sf::Vector2f getDirectionNormalize(sf::Vector2f targetPosition, sf::Vector2f currentPosition);

	static float getMagnitude(sf::Vector2f vector);
	static sf::Vector2f normalizeVector(sf::Vector2f vector);

	static sf::Vector2f randomUnitVector();
};

