#pragma once
#include <glm\glm.hpp>
#include "PhysEntity.h"
using namespace glm;
class Contact
{
private:
	void resolveVelocity(float dt);
	void resolveInterpenetration(float dt);
public:
	float restitution;
	float penetration;
	vec2 ContactNormal;
	PhysEntity* obj[2];
	void resolve(float dt);
	float resolveRestingContact(float dt);
	float computeSeperationalVelocity() const;
	Contact();
	~Contact();

	void setObjects(vector<PhysEntity*> objs);
};

