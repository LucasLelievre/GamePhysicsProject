#include <GL\glut.h> // GLUT, includes glu.h and gl.h
#include "Game.h"
#include "Timer.h"
int refreshMillis = 16;      // Refresh period in milliseconds

Game* game;
LowResTimer timer;
double oldTime = 0;
//vec2* winSize = new vec2(640.0f, 480.0f);

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

/* Callback handler for window re-paint event */
void display() {
	game->Render();
}

/* Call back when the windows is re-sized */
void reshape(GLsizei width, GLsizei height)  {
	game->ReshapeWindow(width, height);
}
/* Call back when a mouse button is pressed */
void button(int button, int state, int x, int y) {
	game->clickMouse(button, state, x, y);
}
/* Call back when mouse is moved */
void motion(int x, int y) {
	if (x >= 0 && x <= 640 && y >= 0 && y <= 480) game->motionMouse(x, y);
}
/* Call back when mouse is moved */
void keyboard(unsigned char key, int x, int y) {
	game->keyboard(key/*, x, y*/);
}

/* Fixed Time Update */
void update(int value) 
{
	game->Update(timer.getTime()-oldTime);
	glutPostRedisplay();						// Post a paint request to activate display()
	glutTimerFunc(refreshMillis, update, 0);	// Subsequent timer call at milliseconds
	oldTime = timer.getTime();
}

void GLUTRenderer()
{
	glutDisplayFunc(display);		// Register callback handler for window re-paint
	glutReshapeFunc(reshape);		// Register callback handler for window re-shape
	glutTimerFunc(0, update, 0);	// First timer call immediately
	initGL();						// Our own OpenGL initialization
	glutMainLoop();					// Enter event-processing loop
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	game = new Game();
	game->Load();
	timer.startTimer();

	glutMouseFunc(button);
	glutPassiveMotionFunc(motion);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);

	GLUTRenderer();

	delete game;

	return 0;
}