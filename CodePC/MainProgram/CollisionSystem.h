#ifndef COLLISIONSYSTEM_HPP
#define COLLISIONSYSTEM_HPP

#include <vector>
#include "ICollision.h"
#include "VectorUtility.h"
#include "PrintDebug.h"

class CollisionSystem
{
public: 
	void CheckCollision(std::vector<ICollision*>& list_a, std::vector<ICollision*>& list_b);

	~CollisionSystem() = default;
};


#endif // !COLLISIONSYSTEM_HPP


