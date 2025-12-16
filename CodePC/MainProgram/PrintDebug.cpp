#include "PrintDebug.h"

void PrintDebug::Print(sf::Vector2f vector)
{
	std::cout << "x: " << vector.x << ", " << "y: " << vector.y << std::endl;
}

void PrintDebug::Print(std::string text)
{
	std::cout << text << std::endl;
}

void PrintDebug::Print(float number)
{
	std::cout << number << std::endl;
}
