#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include <vector>
#include "ICollision.h"

class CollisionSystem
{
public: 
	void CheckCollision(const std::vector<ICollision*>& list_a, const std::vector<ICollision*>& list_b);

	~CollisionSystem() = default;
};


#endif


