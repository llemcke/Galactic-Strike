/*
 * Description: implementation of menu.hpp
* Author: Logan Lemcke
 * Version: 2023-10-01
 */

#include "menu.hpp"
extern int gameState;
extern GLint isInMenu;
void addMenu() {

	glutCreateMenu(mainMenuFcn); // Create main pop-up menu.
	glutAddMenuEntry("Main Menu", 1);
	glutAddMenuEntry("Quit", 2);

}

void mainMenuFcn(GLint menuOption) {
	isInMenu = 1;
	switch (menuOption) {
	case 1:
		gameState=5;
		break;
	case 2:
		exit(0);
	}
	isInMenu = 0;
	glutPostRedisplay();
}


