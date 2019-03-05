#include "PhysEntity.h"

PhysParameters* PhysEntity::getParams() {
	return params;
}

void PhysEntity::setParams(PhysParameters &newParams) {
	*params = newParams;
}



/*PhysEntity::PhysEntity()
{
}


PhysEntity::~PhysEntity()
{
}
*/