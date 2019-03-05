#pragma once
#include <glm\glm.hpp>
using namespace glm;

class Boundaries
{
private:
	vec2 xBounds;
	vec2 yBounds;

public:
	Boundaries(float xMin, float xMax, float yMin, float yMax) :xBounds(xMin, xMax), yBounds(yMin, yMax){}
	virtual ~Boundaries() {}

	vec2 getXBounds();
	vec2 getYBounds();
};