#include "SceneManager.h"

SceneManager::SceneManager()
	: window(sf::VideoMode(WIDTH, HEIGHT), "Asteroid"),
	timePerFrame(sf::seconds(1.f / 60.f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
}

SceneManager::~SceneManager()
{
	delete currentScene;
}

void SceneManager::run()
{
	while (this->window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void SceneManager::handleEvents()
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

void SceneManager::update()
{
	this->elapsedTimeSinceLastUpdate += clock.restart();

	while (elapsedTimeSinceLastUpdate > timePerFrame)
	{
		float deltaTime = timePerFrame.asSeconds();
		elapsedTimeSinceLastUpdate -= timePerFrame;

		currentScene->update(deltaTime);

		if (currentScene->getHasPendingStatus())
		{
			PrintDebug::Print("Switching Scenes " + std::to_string(currentScene->changeTransition()));

			switchScene(currentScene->changeTransition());
		}
	}
}

void SceneManager::render()
{
	this->window.clear();

	currentScene->draw(this->window);

	this->window.display();
}

void SceneManager::switchScene(sceneID id)
{
	delete currentScene;
	currentScene = sceneMap[id];
	currentScene->onEnterScene();
}

