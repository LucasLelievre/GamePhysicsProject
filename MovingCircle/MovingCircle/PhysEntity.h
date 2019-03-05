#pragma once
#include "Entity.h"
#include "PhysParameters.h"

class PhysEntity : public Entity {
private:
	float restitution;
protected:
	PhysParameters* params = nullptr;
public:
	PhysEntity() {}
	virtual ~PhysEntity() {
		if (params != nullptr) delete params;
	}

	virtual void update(float dt) = 0;
	virtual void draw(int width, int height) = 0;

	PhysParameters* getParams();

	void setParams(PhysParameters &params);
};

