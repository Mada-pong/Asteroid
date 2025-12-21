#ifndef GAMEOVERSCENE_HPP
#define GAMEOVERSCENE_HPP

#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(int width, int height);

	// Inherited via Scene
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private: 
	sceneID changeTransition() override;
};

#endif // !GAMEOVERSCENE_HPP
