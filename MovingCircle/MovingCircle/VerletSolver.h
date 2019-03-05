#pragma once
#include "PhysParameters.h"
#include "Solver.h"

class VerletSolver : public Solver{
private:
	void solver(PhysParameters* params, float dt);
public:
	VerletSolver();
	~VerletSolver();
};

