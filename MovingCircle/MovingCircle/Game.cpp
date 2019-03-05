// (c) Marco Gilardi, 2017
#include "Game.h"
#include "Ball.h"
#include <vector>
#include "VerletSolver.h"
#include "Gravity.h"

using namespace std;

void Game::Load()
{
	window = new GameWindow("Physics motion test", 640, 480, 50, 50);
	solver = new VerletSolver;
	forceRegistery = new ForceRegistery;

	Gravity* gravity = new Gravity(vec2(0, -300));
	PhysParameters* params = new PhysParameters(10, vec2(100, 255), vec2(200, 200), 0.0f);
	Ball* ball = new Ball(10, params);
	forceRegistery->add(ball, gravity);
	dynObjs.push_back(ball);
}


void Game::Update(float dt)
{
	forceRegistery->updateForces(dt);
	solver->integrate(dynObjs, dt);
	forceRegistery->clear();
	for (vector<PhysEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
	{
		(*it)->update(dt);
	}

}

void Game::ReshapeWindow(int width, int height)
{
	window->Reshape(width, height);
}

void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear the color buffer
	glMatrixMode(GL_MODELVIEW);		// To operate on the model-view matrix
	for (vector<PhysEntity*>::iterator it = dynObjs.begin(); it < dynObjs.end(); it++)
	{
		(*it)->draw(window->getWidth(), window->getHeight());
	}

	glutSwapBuffers();				// Swap front and back buffers (of double buffered mode)
}

void Game::Inputs()
{
}