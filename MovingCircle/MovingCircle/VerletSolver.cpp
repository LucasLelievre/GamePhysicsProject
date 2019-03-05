#include "VerletSolver.h"



VerletSolver::VerletSolver()
{
}


VerletSolver::~VerletSolver()
{
}

void VerletSolver::solver(PhysParameters* params, float dt) {
	vec2 translation = dt * params->velocity + 0.5f * dt * dt * params->acceleration;
	params->transform.Translate(translation);
	params->velocity += 0.5f * dt *params->acceleration;
	params->acceleration = params->getResultant() * params->getInverseMass();
	params->velocity += 0.5f * dt *params->acceleration;
}