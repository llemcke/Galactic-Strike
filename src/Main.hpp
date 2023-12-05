/*
 * Main.hpp
 *
 *  Created on: Dec 4, 2023
 *      Author: Logan Lemcke
 */

#ifndef MAIN_HPP_
#define MAIN_HPP_
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <GL/glut.h>
#include "menu.hpp"
#include "RGBpixmap.h"
#include <windows.h>  // for playing sound
#include <mmsystem.h>
#include"deathStar.hpp"
#include "planets.hpp"
#include "menu.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include"deathStar.hpp"
#include "planets.hpp"
RGBpixmap pix[14];


int gameState;
int hits;
int counter;
bool motion;
GLint isInMenu=0;
GLsizei winWidth = 800, winHeight = 600;
bool charge;
int index;
bool showMessage = true;
bool startGame=false;
int shots;
const int NUM_TARGETS = 8;  // Number of target planets
Planet temp=Planet(0,0,0,0,0,0,false);
Planet targets[NUM_TARGETS]={temp,temp,temp,temp,temp,temp,temp,temp};
GLint curX;
Deathstar player;
float tarXArr[] = {75, 150, 400, 600, 400, 700, 600, 200};
float tarYArr[] = {100, 300, 400, 100, 100, 100, 200, 300};
float sizeArr[] = {30, 15, 25, 20, 30, 18, 32, 30};
int idArr[] = {4, 5, 6, 7, 8, 9, 10, 11};
float vxArr[] = {0.009, 0.02, 0.02, 0.008, 0.007, 0.009, 0.01, 0.005};
float vyArr[] = {0.01, 0.0, 0.005, 0.01, 0.002, 0.021, 0.03, 0.008};



void start(int value);
void keys(unsigned char key, int x, int y);
void timer(int value);
void welcome();
void endScreenDisplayWin();
void endScreenDisplayLose1();
void endScreenDisplayLose2();
void loadingDisplay();
void display();
void idle();
void update(int value);
void resetLaserCooldown(int value);
void doIt(int value);
void mouseActionFcn(GLint button, GLint action, GLint xMouse, GLint yMouse);
void fixedSizeReshape(GLint newWidth, GLint newHeight);
void init(void);
void initGame();
void winCondition();
void keyboardFunc(unsigned char key, int x, int y);
void initTargets();
void drawTargets();
void drawOpening(int i);
void addMenu();


#endif /* MAIN_HPP_ */
