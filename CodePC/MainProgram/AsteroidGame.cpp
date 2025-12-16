#include "AsteroidGame.h"
#include <iostream>

AsteroidGame::AsteroidGame()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	this->asteroid = new Asteroid(sf::Vector2f(455.836, 200), sf::Vector2f(400, 400), sf::Color::White, 15, sf::Vector2f(WIDTH, HEIGHT));
}

AsteroidGame::~AsteroidGame()
{
	delete player;
	delete asteroid;
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
		spawner->update(timePerFrame.asSeconds());

		//collision.CheckCollision(groupA, spawner->getAsteroids());
	}
}

void AsteroidGame::render()
{
	this->window.clear();

	this->window.draw(*this->player);
	
	this->window.draw(*this->asteroid);

	spawner->draw(window);

	this->window.display();
}

void AsteroidGame::objectCleanup()
{
}
