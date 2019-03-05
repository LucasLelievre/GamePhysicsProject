#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>
#include "Entity.h"

#include "PhysEntity.h"
#include "BoundingSphere.h"


using namespace std;
using namespace glm;

class Ball : public PhysEntity {
private:
	float radius;
	vec3 color;
public:
	Ball(float radius, PhysParameters* params, vec3 color = vec3(0, 1, 1)) : radius(radius), color(color){
		Ball::params = params;
		collider = new BoundingSphere(Ball::radius, params->transform.getPosition());
	}

	virtual ~Ball() {}

	void update(float dt);
	
	void draw(int width, int height);
};