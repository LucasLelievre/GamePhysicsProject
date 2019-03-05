#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>
#include "Observer.h"
#include "Subject.h"
#include "Transform.h"
#include "Entity.h"

class Target :public Entity, public Observer
{
private:
	Transform transform;
	vec3 color;
	float radius;

public:
	Target(float radius, vec2 position, vec3 color) : color(color), radius(radius) 
	{ transform.Translate(position); }

	void update(Subject* subject);
	void update(float dt);
	void draw(int width, int height);
};