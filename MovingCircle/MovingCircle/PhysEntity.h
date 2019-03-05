#pragma once
#include "Entity.h"
#include "PhysParameters.h"
#include "Collider.h"

class PhysEntity : public Entity {
private:
	float restitution;
protected:
	PhysParameters* params = nullptr;

	Collider* collider = nullptr;
public:
	PhysEntity() {}
	virtual ~PhysEntity() {
		if (params != nullptr) delete params;
		if (collider != nullptr) delete collider;
	}

	virtual void update(float dt) = 0;
	virtual void draw(int width, int height) = 0;

	PhysParameters* getParams();

	void setParams(PhysParameters &params);

	Collider* getCollider();
};

