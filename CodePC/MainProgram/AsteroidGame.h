#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Asteroid.h"

class AsteroidGame
{
private:
	static const int WIDTH = 900; 
	static const int HEIGHT = 600;
private: 
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

	Player* player; 
	Asteroid* asteroid; 


	void handleEvents();
	void update();
	void render();
public: 
	AsteroidGame();
	~AsteroidGame();
	void run();
};

