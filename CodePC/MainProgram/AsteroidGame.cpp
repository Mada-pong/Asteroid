#include "AsteroidGame.h"

AsteroidGame::AsteroidGame()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
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
	this->elapsedTimeSinceLastUpdate += clock.restart();

	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		float deltaTime = timePerFrame.asSeconds();
		elapsedTimeSinceLastUpdate -= timePerFrame;

		player.update(deltaTime);
		//asteroidSpawner->update(deltaTime);

		collision.CheckCollision(groupA, asteroidSpawner->getObjectPtrs());
		collision.CheckCollision(player.getSpawner().getObjectPtrs(), asteroidSpawner->getObjectPtrs());
	}
}

void AsteroidGame::render()
{
	this->window.clear();

	this->window.draw(this->player);
	this->window.draw(*this->asteroidSpawner);
	this->window.display();
}

void AsteroidGame::objectCleanup()
{
}
