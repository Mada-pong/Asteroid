#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

class CommonMathExpr
{
private: 
	static const double PI;
public: 
	static double degreeToRad(double degrees);

	static sf::Vector2f getVectorByDegrees(float degrees);
};

