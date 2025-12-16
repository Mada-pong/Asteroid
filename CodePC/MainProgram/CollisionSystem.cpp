#include "CollisionSystem.h"
#include "ICollision.h"
#include "VectorUtility.h"
#include "PrintDebug.h"

void CollisionSystem::CheckCollision(std::vector<ICollision*>& list_a, std::vector<ICollision*>& list_b)
{
	for (size_t a_index = 0; a_index < list_a.size(); a_index++)
	{
		for (size_t b_index = 0; b_index < list_b.size(); b_index++)
		{
			sf::Vector2f direction = VectorUtility::getDirection(
				list_a[a_index]->getCollisionPosition(),
				list_b[b_index]->getCollisionPosition()
			);

			float length = VectorUtility::getMagnitude(direction);

			PrintDebug::Print(length);
		}
	}
}
