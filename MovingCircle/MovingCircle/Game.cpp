// (c) Marco Gilardi, 2017
#include "Game.h"
#include "Ball.h"
#include <vector>
#include "VerletSolver.h"
#include "Gravity.h"
#include "ContactResolver.h"
#include "CollisionDetector.h"

using namespace std;

void Game::Load()
{
	window = new GameWindow("Physics motion test", 640, 480, 50, 50);
	solver = new VerletSolver;
	forceRegistery = new ForceRegistery;

	resolver = new ContactResolver();

	Gravity* gravity = new Gravity(vec2(0, -300));
	PhysParameters* params = new PhysParameters(10, vec2(100, 255), vec2(200, 200), 0.0f);
	Ball* ball = new Ball(10, params);
	forceRegistery->add(ball, gravity);
	dynObjs.push_back(ball);

	params = new PhysParameters(10, vec2(200, 255), vec2(-200, 200), 0.0f);
	ball = new Ball(10, params);
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
	getCollisisonData();

	while (!collisionData.empty()) {
		unique_ptr<CollisionData>& data = collisionData.back();
		resolver->setNumIterations(data->maxNumContacts - data->numContactsLeft);
		if (data->contact != nullptr) resolver->resolverContacts(data->contact, data->numContactsLeft, dt);

		collisionData.pop_back();
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

void Game::getCollisisonData() {
	for (vector<PhysEntity*>::iterator it_obj1 = dynObjs.begin(); it_obj1 < dynObjs.end(); it_obj1++) {
		for (vector<PhysEntity*>::iterator it_obj2 = it_obj1 + 1; it_obj2 < dynObjs.end(); it_obj2++) {
			CollisionData * data = CollisionDetector::CheckCollision(*it_obj1, *it_obj2);
			if (data != nullptr) collisionData.push_back(unique_ptr<CollisionData>(data));
		}
	}
}