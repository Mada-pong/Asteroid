#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

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

	sf::Font font;
	sf::Text text;

	Player* player; 



	void handleEvents();
	void update();
	void render();
public: 
	AsteroidGame();
	~AsteroidGame();
	void run();
};

