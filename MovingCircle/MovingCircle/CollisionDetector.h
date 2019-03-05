#pragma once
// (c) Marco Gilardi, 2017

// Making this class static is a design choice, there are better choices using patterns. However,
// I did not want to overcomplicate this example as the point is showing how things interact not
// implementing patterns.
#include "glm\glm.hpp"
#include "PhysEntity.h"
#include "CollisionData.h"

class BoundingSphere;
class AABB;

using namespace glm;

class CollisionDetector
{
public:
	CollisionDetector() {}
	virtual ~CollisionDetector() {}
	static	CollisionData* CheckCollision(PhysEntity* obj1, PhysEntity* obj2);
private:
	static bool SphereSphereCollision(PhysEntity* obj1, PhysEntity* obj2, CollisionData** data);

	static bool SphereAABBCollision(PhysEntity* obj1, PhysEntity* obj2, CollisionData** data);
	static bool AABBAABBCollision(PhysEntity* obj1, PhysEntity* obj2, CollisionData** data);
};
