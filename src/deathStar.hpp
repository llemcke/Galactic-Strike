/*
 * deathStar.hpp
 *
 *  Created on: Dec 3, 2023
 *      Author: llemc
 */
#ifndef DEATHSTAR_HPP_
#define DEATHSTAR_HPP_

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#include "menu.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include "RGBpixmap.h"
#include <windows.h>  // for playing sound
#include <mmsystem.h> //
#include <GL/glut.h>
struct LaserObject {
	   GLint x;
	   GLint y;

	   bool active;
	};
class Deathstar {
protected:



public:
	bool isLaserActive;
	bool isExploding;
	bool firing;
	int explosionTimer;
	GLfloat cubeX;
	GLfloat cubeY;
	GLfloat cubeSpeed;
	LaserObject laser;
	Deathstar();
	void drawExplosion(GLfloat x, GLfloat y, GLint size);
	void drawDeathStar();
	void draw_Laser(GLint x, GLint y);
	bool checkCollision(GLfloat laserX, GLfloat laserY, GLfloat laserRadius, GLfloat circleX, GLfloat circleY, GLfloat circleRadius);
	void drawTriangle();
	void resetLaserCooldown(int value);
};

#endif /* MENU_HPP_ */



