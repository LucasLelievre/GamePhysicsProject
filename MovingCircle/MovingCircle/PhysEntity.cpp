#include "PhysEntity.h"

PhysParameters* PhysEntity::getParams() {
	return params;
}

void PhysEntity::setParams(PhysParameters &newParams) {
	*params = newParams;
}

Collider* PhysEntity::getCollider() {
	return collider;
}



/*PhysEntity::PhysEntity()
{
}


PhysEntity::~PhysEntity()
{
}
*/