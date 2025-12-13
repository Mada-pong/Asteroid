#include "AsteroidGame.h"
#include <iostream>

AsteroidGame::AsteroidGame()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	this->player = new Player(sf::Vector2f(100, 100), sf::Color::Red, 5);
	this->asteroid = new Asteroid(sf::Vector2f(1800, 400), 
		sf::Vector2f(this->WIDTH / 2, this->HEIGHT / 2),sf::Color::White, 10);
}

AsteroidGame::~AsteroidGame()
{
	delete player;
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
	this->elapsedTimeSinceLastUpdate += clock.restart();

	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		elapsedTimeSinceLastUpdate -= timePerFrame;

		player->update();
		asteroid->update();
	}
}

void AsteroidGame::render()
{
	this->window.clear();

	this->window.draw(*this->player);
	this->window.draw(*this->asteroid);

	this->window.display();
}