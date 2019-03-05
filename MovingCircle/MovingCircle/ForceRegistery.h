#pragma once

#include "PhysParameters.h"
#include "PhysEntity.h"
#include "Force.h"

#include <vector>

using namespace std;

class ForceRegistery
{
private:
	struct ForceRegirstation {
		PhysParameters* params;
		Force* force;
	};
	vector<ForceRegirstation> registrations;
public:
	ForceRegistery();
	virtual ~ForceRegistery() {}

	void add(PhysEntity* obj, Force* fg);
	void remove(PhysEntity* obj, Force* fg);
	void clear();
	void updateForces(float dt);
};

