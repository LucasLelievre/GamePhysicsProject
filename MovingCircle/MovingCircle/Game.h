// (c) Marco Gilardi, 2017
#include <GL\glut.h>
#include <vector>
#include "GameWindow.h"
#include "ForceRegistery.h"
#include "Solver.h"
using namespace std;
#pragma once
class Game
{
private:
	GameWindow* window;
	ForceRegistery* forceRegistery = nullptr;
	Solver* solver = nullptr;
	vector<PhysEntity*> dynObjs;

public:
	void Load();
	//void GameLoop();
	void Render();
	void Inputs();
	void Update(float dt);
	void ReshapeWindow(int weigth, int height);

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

	//Timer* gameTimer;
	//float lastFrameTime;

};