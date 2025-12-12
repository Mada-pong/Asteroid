#include "AsteroidGame.h"
#include <iostream>

AsteroidGame::AsteroidGame()
	: window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	this->player = new Player(sf::Vector2f(this->WIDTH, this->HEIGHT / 2), sf::Color::Red, 5);
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
	while (auto event = window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window.close();
		}
	}
}

void AsteroidGame::update()
{
	this->elapsedTimeSinceLastUpdate += clock.restart();

	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		elapsedTimeSinceLastUpdate -= timePerFrame;

		player->update();
	}
}

void AsteroidGame::render()
{
	this->window.clear();

	this->window.draw(*this->player);

	this->window.display();
}