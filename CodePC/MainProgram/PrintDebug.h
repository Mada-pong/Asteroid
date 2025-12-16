#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class PrintDebug
{
public: 
	static void Print(sf::Vector2f vector);
	static void Print(std::string text);
	static void Print(float number);
};

