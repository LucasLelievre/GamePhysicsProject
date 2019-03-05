#include "Target.h"
#include <iostream>
#include<glm\glm.hpp>
using namespace std;
using namespace glm;

void Target::update(Subject* subject)
{
	if( length(transform.getPosition()-subject->getPosition()) < radius+subject->getRadius())
		cout << "Hit!" << endl;
}

void Target::update(float dt)
{

}

void Target::draw(int width, int height)
{
	vec2 position = transform.getPosition();
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos)

																  // Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(color.r, color.g, color.b);								// Cyan
	glVertex2f(0.0f, 0.0f);										// Center of circle
	int numSegments = 100;
	float angle;
	for (int i = 0; i <= numSegments; i++) {					// Last vertex same as first vertex
		angle = i * 2.0f * pi<float>() / numSegments;			// 360 deg for all segments
		glVertex2f(cos(angle) * (2.0f * radius / width)* aspectRatio,
			sin(angle) * (2.0f * radius / height));
	}
	glEnd();
}
