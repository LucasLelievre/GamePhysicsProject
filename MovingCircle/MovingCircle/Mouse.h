#pragma once
#include <iostream>
#include <gl/glut.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

class Mouse
{
public:
private:
	float mouseX, mouseY;
public:
	Mouse() : mouseX(-5.0), mouseY(5.0) {}
	virtual ~Mouse() {}

	void button(int button, int state, int x, int y);
	void motion(int x, int y);
	vec2 getMouse();
	void setMouse(vec2 pos);
};

