#include "Contact.h"



Contact::Contact()
{
}

float Contact::computeSeperationalVelocity() const
{
	vec2 relVelocity = obj[0]->getParams()->velocity;
	if (obj[1]) relVelocity -= obj[1]->getParams()->velocity;
	return dot(relVelocity, ContactNormal);
}

void Contact::resolve(float dt)
{
	resolveVelocity(dt);
	resolveInterpenetration(dt);
}

void Contact::resolveInterpenetration(float dt)
{
	if (penetration >= 0)return;
	float totalInvMass = obj[0]->getParams()->getInverseMass();
	if (obj[1]) totalInvMass += obj[1]->getParams()->getInverseMass();
	if (totalInvMass <= 0) return;

	vec2 movePerUnitMass = ContactNormal * (-penetration / totalInvMass);

	obj[0]->getParams()->transform.Translate(0.5f*(movePerUnitMass * obj[0]->getParams()->getInverseMass()));
	obj[0]->getParams()->velocity += 0.5f * dot((movePerUnitMass * obj[0]->getParams()->getInverseMass()) / dt, ContactNormal)*ContactNormal;
	if (obj[1]) {
		obj[1]->getParams()->transform.Translate(0.5f*(movePerUnitMass * obj[1]->getParams()->getInverseMass()));
		obj[1]->getParams()->velocity -= 0.5f * dot((movePerUnitMass * obj[1]->getParams()->getInverseMass()) / dt, ContactNormal)*ContactNormal;
	}

}

 float Contact::resolveRestingContact(float dt)
{
	 vec2 accCausedVel = obj[0]->getParams()->acceleration;
	 if (obj[1]) accCausedVel += obj[1]->getParams()->acceleration;
	 float accCausedSepVel = dot(accCausedVel, ContactNormal) * dt;
	 if (accCausedSepVel < 0)
		 return restitution * accCausedSepVel;
	 else
		 return 0;
}

 void Contact::resolveVelocity(float dt)
 {
	 float separatingVelocity = computeSeperationalVelocity(); //velocity along normal
	 if (separatingVelocity > 0) return;
	 float newSepVel = -separatingVelocity * (1 + restitution) + resolveRestingContact(dt);
	 if (newSepVel < 0) newSepVel = 0;
	 float totalnvMass = obj[0]->getParams()->getInverseMass();
	 if (obj[1]) totalnvMass += obj[1]->getParams()->getInverseMass();
	 if (totalnvMass < 0) return;
	 float impulseLength = newSepVel / totalnvMass;
	 vec2 impulse = impulseLength * ContactNormal;

	 obj[0]->getParams()->velocity = obj[0]->getParams()->velocity + impulse * obj[0]->getParams()->getInverseMass();
	 if (obj[1])
		 obj[1]->getParams()->velocity = obj[1]->getParams()->velocity - impulse * obj[1]->getParams()->getInverseMass();
 }
Contact::~Contact()
{
}

void Contact::setObjects(vector<PhysEntity*> objs) {
	obj[0] = objs[0];
	obj[1] = objs[1];
}
