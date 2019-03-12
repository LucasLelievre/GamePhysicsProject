#pragma once
#include <glm\glm.hpp>
#include <gl/glut.h>
#include<iostream>

using namespace glm;
using namespace std;

class Gun
{
private:
	vec2 pos;
public:
	Gun(vec2 pos) : pos(pos) {};
	~Gun();
	void shoot(float x, float y);
};

