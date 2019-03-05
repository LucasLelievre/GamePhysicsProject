#include "Solver.h"

void Solver::integrate(vector<PhysEntity*> &dynObjs, float dt) {
	for (vector<PhysEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++) {
		PhysParameters* params = (*it)->getParams();
		solver(params, dt);
	}
}
