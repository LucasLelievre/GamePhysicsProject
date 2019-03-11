#include "Mouse.h"



void Mouse::button(int button, int state, int x, int y) {
	if (!state) { // Are there any buttons down?
		switch (button) { // Which button?
		case GLUT_LEFT_BUTTON: // Shoot
			break;
		case GLUT_RIGHT_BUTTON: // boop
			break;
		}
	}
	else { // No buttons pressed.
	}
}

void Mouse::motion(int x, int y) {
	mouseX = (float)x;
	mouseY = (float)y;
}

vec2 Mouse::getMouse() {
	return vec2(mouseX, 500 - mouseY);
}
void Mouse::setMouse(vec2 pos) {
	mouseX = pos.x;
	mouseY = pos.y;
}
