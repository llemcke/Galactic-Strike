/*
 * deathStar.hpp
 *
 *  Created on: Dec 3, 2023
 *      Author: llemc
 */
#ifndef PLANETS_HPP_
#define PLANETS_HPP_

#include <GL/glut.h>
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
class Planet {
protected:



public:

	bool active;

	GLfloat x;
	GLfloat y;
	GLfloat velocityX;
	GLfloat velocityY;
	GLfloat radius;
	GLint tID;
	Planet(int x, int y, int r,int texture, float VX, float VY,bool act);
	void drawPlanet();

};

#endif



