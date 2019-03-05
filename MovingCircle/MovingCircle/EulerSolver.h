#pragma once
#include "PhysParameters.h"
#include "Solver.h"

class EulerSolver : public Solver{
private:
	void solver(PhysParameters* params, float dt);
public:
	EulerSolver();
	virtual ~EulerSolver();

	void integrate(vector<PhysEntity*> &dynObjs, float dt);
};

