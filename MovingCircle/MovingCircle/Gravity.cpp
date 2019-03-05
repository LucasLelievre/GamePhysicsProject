#include "Gravity.h"
#include "PhysParameters.h"

void Gravity::updateForce(PhysParameters* param, float dt) {
	param->addForce(gravity * param->getMass());
}