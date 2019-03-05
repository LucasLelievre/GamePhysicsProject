#pragma once

#include <glm\glm.hpp>
#include "Transform.h"
#include "Utils.h"


struct PhysParameters {
private:
	float inverseMass;
	vec2 forceAccum;

	float restitution;

public:
	Transform transform;
	vec2 velocity;
	vec2 acceleration;

	PhysParameters(float mass, vec2 pos, vec2 vel, float restit = 0) : velocity(vel), restitution(restit), forceAccum(vec2(0)), acceleration(vec2(0)), inverseMass(INFINITY) {
		setInvMass(mass);
		transform.Translate(pos);
	}

	virtual ~PhysParameters() {}

	float getMass();
	float getInverseMass();
	vec2 getResultant();
	float getRestitution();

	void setInvMass(float mass);
	void setRestitution(float restit);

	void clearAccumulator();
	void addForce(vec2& force);

	void Print();
};



