#pragma once

#include "PhysParameters.h"
#include "PhysEntity.h"
#include <vector>

using namespace std;

class Solver {
private:
	virtual void solver(PhysParameters* params, float dt) = 0;
public:
	void integrate(vector<PhysEntity*> &dynObjs, float dt);
};

