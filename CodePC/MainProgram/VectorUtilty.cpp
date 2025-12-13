#include "VectorUtility.h"

const double VectorUtility::PI = 3.14159265358979323846;

double VectorUtility::degreeToRad(double degrees)
{
	double radians = degrees * PI / 180;
	return radians;
}

sf::Vector2f VectorUtility::getVectorByDegrees(float degrees)
{
	double x = std::cos(degreeToRad(degrees));
	double y = std::sin(degreeToRad(degrees));

	return sf::Vector2f(x, y);
}

sf::Vector2f VectorUtility::getDirection(sf::Vector2f targetPosition, sf::Vector2f currentPosition)
{
	return targetPosition - currentPosition;
}

sf::Vector2f VectorUtility::getDirectionNormalize(sf::Vector2f targetPosition, sf::Vector2f currentPosition)
{
	sf::Vector2f targetDirection = getDirection(targetPosition, currentPosition);
	float length = getMagnitude(targetDirection);

	return sf::Vector2f(targetDirection.x / length, targetDirection.y / length);
}

float VectorUtility::getMagnitude(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}
