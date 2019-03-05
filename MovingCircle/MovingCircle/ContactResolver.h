#pragma once
#include "Contact.h"
class ContactResolver
{
private :
	int numIterations;
	int iteration;
public:
	ContactResolver() {}
	ContactResolver(int numIterations) : numIterations(numIterations) {}
	void resolverContacts(Contact* contactArray, int numContects, float dt);
	void setNumIterations(int num);
};

