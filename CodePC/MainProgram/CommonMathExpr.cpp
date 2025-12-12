#include "CommonMathExpr.h"

const double CommonMathExpr::PI = 3.14159265358979323846;

double CommonMathExpr::degreeToRad(double degrees)
{
	double radians = degrees * PI / 180;
	return radians;
}

sf::Vector2f CommonMathExpr::getVectorByDegrees(float degrees)
{
	double x = std::cos(degreeToRad(degrees));
	double y = std::sin(degreeToRad(degrees));

	return sf::Vector2f(x, y);
}
