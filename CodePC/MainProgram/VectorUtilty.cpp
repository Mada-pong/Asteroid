#include "VectorUtility.h"

/// <summary>
/// Maybe redo VectorUtility to use chain building but this is good enough for now
/// </summary>

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

	return normalizeVector(targetDirection);
}

/// <summary>
/// getMagnitude gets the length of the entire vector
/// </summary>
/// <param name="vector"></param>
/// <returns></returns>
float VectorUtility::getMagnitude(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f VectorUtility::normalizeVector(sf::Vector2f vector)
{
	float length = getMagnitude(vector);
	return sf::Vector2f(vector.x / length, vector.y / length);
}

sf::Vector2f VectorUtility::randomUnitVector()
{
	std::random_device rd; 
	std::uniform_real_distribution<float> dist(-1, 1);

	float x = dist(rd);
	float y = dist(rd);

	return normalizeVector(sf::Vector2f(x, y));
}
