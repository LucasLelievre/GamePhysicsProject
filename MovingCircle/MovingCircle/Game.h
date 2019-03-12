// (c) Marco Gilardi, 2017
#include <GL\glut.h>
#include <vector>
#include <memory>
#include "GameWindow.h"
#include "Mouse.h"
#include "ForceRegistery.h"
#include "Solver.h"
#include "ContactResolver.h"
#include "CollisionData.h"
using namespace std;
#pragma once
class Game
{
private:
	GameWindow* window;
	Mouse* mouse;
	ForceRegistery* forceRegistery = nullptr;
	Solver* solver = nullptr;
	vector<PhysEntity*> dynObjs;

	vector<unique_ptr<CollisionData>> collisionData;
	ContactResolver* resolver = nullptr;

	//Gun* gun;
public:
	void Load();
	//void GameLoop();
	void Render();
	void Inputs();
	void Update(float dt);
	void ReshapeWindow(int weigth, int height);
	void clickMouse(int button, int state, int x, int y);
	void motionMouse(int x, int y);
	void keyboard(unsigned char key/*, int x, int y*/);

	Game() {};
	virtual ~Game() 
	{ 
		for (vector<PhysEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
		{
			delete(*it);
		}

		if (solver != nullptr) delete solver;
		if (window != nullptr) delete window;
		if (forceRegistery != nullptr) delete forceRegistery;
	}

	void getCollisisonData();

};