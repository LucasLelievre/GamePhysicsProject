#include "ContactResolver.h"




void ContactResolver::resolverContacts(Contact* contactArray, int numContacts, float dt) {
	iteration = 0;
	while (iteration < numIterations) {
		float max = 0;
		int maxIndex = numContacts;
		for (int i = 0; i < numContacts; i++) {
			float sepVel = contactArray[i].computeSeperationalVelocity();
			if (sepVel < max) {
				max = sepVel;
				maxIndex = i;
			}
		}
		contactArray[maxIndex].resolve(dt);
		iteration++;
	}
}

void ContactResolver::setNumIterations(int num) {
	numIterations = num;
}

