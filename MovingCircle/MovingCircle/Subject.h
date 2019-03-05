#pragma once
#include <vector>
#include "Observer.h"
#include<glm\glm.hpp>
using namespace std;
using namespace glm;

class Subject
{
protected:
	vector<Observer*> observers;
public:
	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObserver() = 0;
	virtual void removeObserver(Observer* observer) = 0;

	virtual vec2 getPosition() = 0;
	virtual float getRadius() = 0;
};