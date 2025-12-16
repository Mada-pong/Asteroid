#include "CollisionSystem.h"
#include "ICollision.h"
#include "VectorUtility.h"
#include "PrintDebug.h"

void CollisionSystem::CheckCollision()
{
}

CollisionSystem::CollisionSystem(std::vector<ICollision>& list_a, std::vector<ICollision>& list_b)
	: list_A(list_a), list_B(list_B)
{
}

void CollisionSystem::update()
{
}