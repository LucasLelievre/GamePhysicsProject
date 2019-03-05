#pragma once

#include <glm\glm.hpp>
#include "PhysParameters.h"
#include "Force.h"

class Gravity : public Force {
private:
	vec2 gravity;

public:
	Gravity(const vec2& gravity) : gravity(gravity) {}
	virtual ~Gravity() {};

	void updateForce(PhysParameters* param, float dt);
};