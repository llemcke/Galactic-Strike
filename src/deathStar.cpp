/*
 * deathStar.cpp
 *
 *  Created on: Dec 3, 2023
 *      Author: llemc
 */

#include "deathStar.hpp"



Deathstar::Deathstar(){
	isLaserActive=false;
	isExploding=false;
	firing=false;
	explosionTimer=0;
	cubeX = 400.0;
	cubeY = 520.0;
	cubeSpeed = 15.0;
	laser.x=0;
	laser.y=0;
	laser.active=false;

}

void Deathstar::drawTriangle(){


	    glColor3f(0.0, 1.0, 0.0);  // Set color to green

	    glBegin(GL_TRIANGLES);
	    glVertex2f(cubeX, cubeY);
	    glVertex2f(cubeX+50, cubeY);
	    glVertex2f(cubeX+25, cubeY-50);
	    glEnd();

	    glFlush();
}

void Deathstar::drawExplosion(GLfloat x, GLfloat y, GLint size){
	size+=10;
	glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(x-size,y-size);
    glTexCoord2f(1.0, 0.0); glVertex2f(x+size,y-size);
    glTexCoord2f(1.0, 1.0); glVertex2f(x+size,y+size);
    glTexCoord2f(0.0, 1.0); glVertex2f(x-size,y+size);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void Deathstar::drawDeathStar() {
	glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);


    glBegin(GL_TRIANGLE_FAN);

    // Center of the circle
    GLfloat centerX = cubeX + 25;
    GLfloat centerY = cubeY + 25;

    // Radius of the circle
    GLfloat radius = 50.0;

    // Number of segments to approximate the circle
    int numSegments = 100;

    // Draw the circle using a triangle fan
    for (int i = 0; i <= numSegments; ++i) {
        GLfloat theta = static_cast<GLfloat>(i) / static_cast<GLfloat>(numSegments) * 2.0 * M_PI;
        GLfloat x = centerX + radius * cos(theta);
        GLfloat y = centerY + radius * sin(theta);
        glTexCoord2f((x - (cubeX + 25)) / 50.0, (y - (cubeY + 25)) / 50.0);  // Adjust texture coordinates
        glVertex2f(x, y);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void Deathstar::draw_Laser(GLint x, GLint y) {
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(x-3, y);
    glVertex2i(x+ 3, y);
    glVertex2i(x + 3, y + 60);
    glVertex2i(x-3, y + 60);
    glEnd();
}
bool Deathstar::checkCollision(GLfloat laserX, GLfloat laserY, GLfloat laserRadius, GLfloat circleX, GLfloat circleY, GLfloat circleRadius) {
    GLfloat dx = circleX - laserX;
    GLfloat dy = circleY - laserY;
    GLfloat distance = sqrt(dx * dx + dy * dy);

    return distance < (laserRadius + circleRadius);
}



