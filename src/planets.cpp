/*
 * deathStar.cpp
 *
 *  Created on: Dec 3, 2023
 *      Author: llemc
 */
#include "planets.hpp"





Planet::Planet(int X, int Y, int r, int texture, float VX, float VY, bool act){

	active=act;
	x=X;
	y=Y;
	radius=r;
	tID=texture;
	velocityX=VX;
	velocityY=VY;
}
void Planet::drawPlanet() {
	glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->tID);
    glBegin(GL_TRIANGLE_FAN);

    // Center of the circle
    GLfloat centerX = this->x ;
    GLfloat centerY = this->y;

    // Radius of the circle
    GLfloat radius = this->radius;

    // Number of segments to approximate the circle
    int numSegments = 100;

    // Draw the circle using a triangle fan
    for (int i = 0; i <= numSegments; ++i) {
        GLfloat theta = static_cast<GLfloat>(i) / static_cast<GLfloat>(numSegments) * 2.0 * M_PI;
        GLfloat x = centerX + radius * cos(theta);
        GLfloat y = centerY + radius * sin(theta);
        glTexCoord2f((x - (this->x)) / 50.0, (y - (this->y)) / 50.0);  // Adjust texture coordinates
        glVertex2f(x, y);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}





