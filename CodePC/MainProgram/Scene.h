#ifndef SCENE_HPP
#define SCENE_HPP

#include "SceneID.h"
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene(int width, int height) : WIDTH(width), HEIGHT(height) {};
	virtual ~Scene() = default;

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	virtual sceneID changeTransition() = 0;

	virtual void onEnterScene() = 0;

	virtual bool getHasPendingStatus() { return hasPendingTransition; };
protected:
	bool hasPendingTransition = false;
	const int WIDTH; 
	const int HEIGHT; 
};

#endif
