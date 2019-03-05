#include "ForceRegistery.h"



ForceRegistery::ForceRegistery()
{
}

void ForceRegistery::add(PhysEntity* obj, Force* fg) {
	ForceRegirstation fr;
	fr.force = fg;
	fr.params = obj->getParams();
	registrations.push_back(fr);
}
void ForceRegistery::remove(PhysEntity* obj, Force* fg) {
	for (vector<ForceRegirstation>::iterator it = registrations.begin(); it < registrations.end(); it++) {
		if (it->params == obj->getParams()) {
			registrations.erase(it);
			break;
		}
	}
}
void ForceRegistery::clear() {
	for (vector<ForceRegirstation>::iterator it = registrations.begin(); it < registrations.end(); it++) {
		it->params->clearAccumulator();
	}
}
void ForceRegistery::updateForces(float dt) {
	for (vector<ForceRegirstation>::iterator it = registrations.begin(); it < registrations.end(); it++) {
		it->force->updateForce(it->params, dt);
	}
}