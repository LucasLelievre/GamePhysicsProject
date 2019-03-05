#include "PhysParameters.h"


float PhysParameters::getMass() {
	return 1 / inverseMass;
}
float PhysParameters::getInverseMass() {
	return inverseMass;
}
vec2 PhysParameters::getResultant() {
	return forceAccum;
}
float PhysParameters::getRestitution() {
	return restitution;
}

void PhysParameters::setInvMass(float mass) {
	inverseMass = 1 / mass;
}
void PhysParameters::setRestitution(float restit) {
	restitution = Utils::clamp(restit);
}

void PhysParameters::clearAccumulator() {
	forceAccum = vec2(0);
}
void PhysParameters::addForce(vec2& force) {
	forceAccum += force;
}
void PhysParameters::Print() {
	cout << getInverseMass() << "  " << transform.getPosition().x << " " << transform.getPosition().y << "  " << velocity.x << " " << velocity.y << endl;
}

void PhysParameters::setPosition(vec2 pos)
{
	transform.Translate(pos);

}