/*
 * Description: SimpleDraw menu function header
* Author: Logan Lemcke
 * Version: 2023-10-01
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>
#include <GL/glut.h>


#include <windows.h>  // for playing sound
#include <mmsystem.h>
#include"deathStar.hpp"


void addMenu();

void mainMenuFcn(GLint menuOption);

void resetGame();

#endif /* MENU_HPP_ */
