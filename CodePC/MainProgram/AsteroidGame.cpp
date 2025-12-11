#include "AsteroidGame.h"
#include <iostream>

AsteroidGame::AsteroidGame()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	this->font.loadFromFile("../Font/arial.ttf");

	this->text.setFont(font);
	this->text.setString("Hello world");

	this->text.setCharacterSize(24);
	this->text.setFillColor(sf::Color::Red);
}

AsteroidGame::~AsteroidGame()
{
}

void AsteroidGame::run()
{
	while (this->window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void AsteroidGame::handleEvents()
{
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window.close();
		}
	}
}

void AsteroidGame::update()
{

}

void AsteroidGame::render()
{
	this->window.clear();

	this->window.draw(text);

	this->window.display();
}