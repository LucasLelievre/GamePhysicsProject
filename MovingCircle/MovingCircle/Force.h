#pragma once
#include "PhysParameters.h"


class Force {
private:

public:
	Force() {};
	virtual ~Force() {};

	virtual void updateForce(PhysParameters* param, float dt) = 0;
};