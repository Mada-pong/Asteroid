#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include <vector>
#include "ICollision.h"

class CollisionSystem
{
private:
	std::vector<ICollision>& list_A;
	std::vector<ICollision>& list_B;

	void CheckCollision();
public: 
	CollisionSystem(std::vector<ICollision>& list_a, std::vector<ICollision>& list_b);

	void update();
};


#endif // !COLLISIONSYSTEM_HPP

