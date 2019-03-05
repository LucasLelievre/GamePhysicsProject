#include "EulerSolver.h"



EulerSolver::EulerSolver()
{
}


EulerSolver::~EulerSolver()
{
}

void EulerSolver::solver(PhysParameters* params, float dt) {
	params->transform.Translate(dt * params->velocity);
	params->velocity += dt * params->acceleration;
	params->acceleration = params->getResultant() * params->getInverseMass();
}