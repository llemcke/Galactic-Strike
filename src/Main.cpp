/*
 * Description: Main Program for Galactic Destroyer

* Author: Logan Lemcke, Connor Doidge, Jack Waslen
 * Version: 2023-12-01
 */


#include "main.hpp"





void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Galactic Strike - Logan Lemcke/Jack Waslen/Connor Doidge");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	initTargets();
	initGame();
}

void initGame(){
	initTargets();
	pix[0].makeCheckerboard();
	pix[0].setTexture(0);
	pix[1].readBMPFile("textures/death.bmp");
	pix[1].setTexture(1);
	pix[2].readBMPFile("textures/explosion.bmp");
	pix[2].setTexture(2);
	pix[3].readBMPFile("textures/darth.bmp");
	pix[3].setTexture(3);
	pix[4].readBMPFile("textures/earth.bmp");
	pix[4].setTexture(4);
	pix[5].readBMPFile("textures/moon.bmp");
	pix[5].setTexture(5);
	pix[6].readBMPFile("textures/sun.bmp");
	pix[6].setTexture(6);
	pix[7].readBMPFile("textures/red.bmp");
	pix[7].setTexture(7);
	pix[8].readBMPFile("textures/Beige.bmp");
	pix[8].setTexture(8);
	pix[9].readBMPFile("textures/river.bmp");
	pix[9].setTexture(9);
	pix[10].readBMPFile("textures/jupiter.bmp");
	pix[10].setTexture(10);
	pix[11].readBMPFile("textures/Mars.bmp");
	pix[11].setTexture(11);
	pix[12].readBMPFile("textures/lose.bmp");
	pix[12].setTexture(12);
	pix[13].readBMPFile("textures/darth_happy.bmp");
	pix[13].setTexture(13);
	counter=0;
	motion=true;
	gameState=1;
	hits=0;
	charge=false;
	shots=10;
	glutTimerFunc(0, timer, 0);
}


void winCondition(){
	if (hits==8){
		PlaySound((LPCSTR) "sounds/laugh.wav", NULL, SND_FILENAME | SND_ASYNC);
		gameState=4;
	}
	else if (hits>=5){
		PlaySound((LPCSTR) "sounds/no.wav", NULL, SND_FILENAME | SND_ASYNC);
		gameState=6;
	}
	else{
		PlaySound((LPCSTR) "sounds/victory.wav", NULL, SND_FILENAME | SND_ASYNC);
		gameState=7;
	}
	glutPostRedisplay();
}
void keyboardFunc(unsigned char key, int x, int y) {
	if (gameState==3&& !player.firing){
    switch (key) {
        case 'a':
        if (player.cubeX>0){
            player.cubeX -= player.cubeSpeed;
        }
        break;
        case 'd':
        if (player.cubeX+75<winWidth){
        	player.cubeX += player.cubeSpeed;
        }

        break;
    }

    // Redraw the scene
    glutPostRedisplay();
	}
}




void initTargets() {
    for (int i = 0; i < NUM_TARGETS; i++) {
    	targets[i].x=tarXArr[i];
    	targets[i].y=tarYArr[i];
    	targets[i].radius=sizeArr[i];
        targets[i].tID = idArr[i];
        targets[i].velocityX = vxArr[i];
        targets[i].velocityY = vyArr[i];
        targets[i].active = true;

    }

}

void drawTargets() {
    glColor3f(0.0, 0.0, 1.0);  // Set color to green for targets
    for (int i = 0; i < NUM_TARGETS; i++) {
    	if(targets[i].active){
        targets[i].drawPlanet();
    	}
    }
}
void drawOpening(int i){
		glColor3f(1, 1, 1);
	    glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, i);
	    glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 1.0); glVertex2f(-0.2, 0.4);
	    glTexCoord2f(1.0, 1.0); glVertex2f(0.3, 0.4);
	    glTexCoord2f(1.0, 0.0); glVertex2f(0.3, -0.1);
	    glTexCoord2f(0.0, 0.0); glVertex2f(-0.2, -0.1);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
}
void timer(int value) {
	if (gameState==1){
		showMessage = !showMessage;
    	glutTimerFunc(500, timer, 0);
    }

}
void welcome(){

	glutKeyboardFunc(keys);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.3, 0.5);
	drawOpening(3);

	    const char* msg = "Welcome to the Death Star";
	    while (*msg) {
	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg);
	        msg++;
	    }
	    if (showMessage) {
	    glColor3f(1.0, 0.0, 0.0);
	    glRasterPos2f(-0.4, -0.3);

	    const char* msg1 = "Press Space to start destroying planets";
	    while (*msg1) {
	    	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg1);
	    	 msg1++;
	    }
	    glColor3f(1.0, 1.0, 1.0);
	    	    glRasterPos2f(0.2, 0.2);
	    	    const char* msg2 = "Dew it";
	    	    while (*msg2) {
	    	    	 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg2);
	    	    	 msg2++;
	    	    }
	    }

	    glutSwapBuffers();


}
void endScreenDisplayWin(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.3, 0.5);

		drawOpening(13);
	    const char* msg = "The planets have been destroyed!";
	    while (*msg) {
	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg);
	        msg++;
	    }
	        glColor3f(1.0, 0.0, 0.0);
	        glRasterPos2f(-0.4, -0.3);

	        const char* msg1 = "Your Galactic Empire now reigns supreme!";
	        while (*msg1) {
	            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg1);
	            msg1++;
	        }
	        glutSwapBuffers();
	}
void endScreenDisplayLose1(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.3, 0.5);
		drawOpening(3);
	    const char* msg = "Some of the Rebel scum got away!";
	    while (*msg) {
	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg);
	        msg++;
	    }
	        glColor3f(1.0, 0.0, 0.0);
	        glRasterPos2f(-0.2, -0.3);

	        const char* msg1 = "Better luck next time!";
	        while (*msg1) {
	            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg1);
	            msg1++;
	        }
	        glutSwapBuffers();
	}

void endScreenDisplayLose2(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.3, 0.5);
		drawOpening(12);
	    const char* msg = "You failed to blow up the planets!";
	    while (*msg) {
	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg);
	        msg++;
	    }


	        glColor3f(1.0, 0.0, 0.0);
	        glRasterPos2f(-0.4, -0.3);

	        const char* msg1 = "The rebels have blown up your Death Star";
	        while (*msg1) {
	            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg1);
	            msg1++;
	        }
	    glutSwapBuffers();

}

void loadingDisplay(){

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-0.1, 0.0);
	    const char* msg = "Loading...";
	    while (*msg) {
	        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *msg);
	        msg++;
	    }
		glRasterPos2f(-0.2, -0.4);
		    const char* msg1 = "Left mouse to fire, a and d to move";
		    while (*msg1) {
		        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *msg1);
		        msg1++;
		    }
	    glutSwapBuffers();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	  for (int i = 0; i < NUM_TARGETS; ++i) {
		  counter++;
			if (counter>=50000){
				motion=!motion;
				counter=0;
			}
			if (motion){
				targets[i].x += targets[i].velocityX;
				targets[i].y += targets[i].velocityY;
			}
			else{
				targets[i].x -= targets[i].velocityX;
				targets[i].y -= targets[i].velocityY;

			}

	 }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLdouble(winWidth), GLdouble(winHeight), 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);


    drawTargets();
    player.drawDeathStar();
    if (player.firing && charge){
    	player.drawTriangle();
    }

        if (player.laser.active) {
            player.draw_Laser(player.laser.x, player.laser.y);
        }
        if (player.isExploding){
        	player.explosionTimer++;
        	if (player.explosionTimer<=1000){
        		player.drawExplosion(targets[index].x,targets[index].y,targets[index].radius);
        	}
        	else{
        		player.isExploding=false;
        		player.explosionTimer=0;
        	}
        }

        glColor3f(1.0, 1.0, 1.0);
           glRasterPos2f(winWidth - 150, 20);

           char hitsStr[16];
           sprintf(hitsStr,"%d", hits);
           const char* msg = "Score: ";
           char combinedMsg[100];


           sprintf(combinedMsg, "%s%s", msg, hitsStr);
           const char* displayMsg = combinedMsg;
           while (*displayMsg) {
               glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *displayMsg);
               displayMsg++;
           }

           glColor3f(1.0, 1.0, 1.0);
              glRasterPos2f(winWidth - 150, 50);

              char shotstr[16];
              sprintf(shotstr,"%d", shots);
              const char* msg1 = "Shots: ";
              char combinedMsg1[100];


              sprintf(combinedMsg1, "%s%s", msg1, shotstr);
              const char* displayMsg1 = combinedMsg1;
              while (*displayMsg1) {
                  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *displayMsg1);
                  displayMsg1++;
              }

    glutPostRedisplay();
    glutSwapBuffers();
}
void idle() {
	switch (gameState) {

		case 1:
			welcome();
			break;

		case 2:
			loadingDisplay();
			break;

		case 3:
			display();
			break;

		case 4:
			endScreenDisplayWin();
			break;
		case 5:
			player.laser.active=false;
			player.firing=false;
			initGame();
			break;
		case 6:
			endScreenDisplayLose1();
			break;
		case 7:
			endScreenDisplayLose2();
			break;

	}
		glutPostRedisplay();

}


void update(int value) {

    if (player.laser.active) {
    	player.firing=false;
    	charge=false;

        player.laser.y -= 5;


        for (int i = 0; i < NUM_TARGETS; ++i) {
        	if(targets[i].active){
            if (player.checkCollision(player.laser.x, player.laser.y, 10.0, targets[i].x, targets[i].y, targets[i].radius)) {
                player.laser.active = false;  // Deactivate the laser
                targets[i].active=false;
                player.isExploding=true;
                index=i;
                PlaySound((LPCSTR) "sounds/explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
                hits+=1;
                if (hits>=NUM_TARGETS){
                	winCondition();
                }
                else if (shots==0){
                	winCondition();
                }
                break;
            }
        }
        }


        if (player.laser.y <= 0) {
           player.laser.active = false;
           if (shots==0){
        	   winCondition();
           }
        }
    }

    glutPostRedisplay();


    if (player.laser.active) {
        glutTimerFunc(16, update, 0);
    }
}
void resetLaserCooldown(int value) {
	player.laser.x = player.cubeX+25;
	player.laser.y = player.cubeY-60;
	curX=player.laser.x;
	player.laser.active = true;
	charge=false;

	glutTimerFunc(0, update, 0);
}
void doIt(int value){
	PlaySound((LPCSTR) "sounds/laser.wav", NULL, SND_FILENAME | SND_ASYNC);
	if (gameState==3){
	       charge=true;
	}

	glutTimerFunc(1000, resetLaserCooldown, 0);
}
void mouseActionFcn(GLint button, GLint action, GLint xMouse, GLint yMouse) {
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN &&gameState==3) {
        // Check if there's an available laser slot and no laser is currently active
        if (!player.laser.active&& !player.firing) {

        	shots--;
        	player.firing=true;
        	PlaySound((LPCSTR) "sounds/do-it.wav", NULL, SND_FILENAME | SND_ASYNC);
        	glutTimerFunc(1000, doIt, 0);
        }
    }
}



void fixedSizeReshape(GLint newWidth, GLint newHeight) {
	glutReshapeWindow(winWidth, winHeight);

}
void start(int value){
	gameState=3;
	glutPostRedisplay();
	glutMouseFunc(mouseActionFcn);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutPostRedisplay();

}
void keys(unsigned char key, int x, int y){
	if (key==' '){
		gameState=2;
		glutKeyboardFunc(keyboardFunc);
		PlaySound((LPCSTR) "sounds/thats-no-moon.wav", NULL, SND_FILENAME | SND_ASYNC);
		glutPostRedisplay();
		glutTimerFunc(5000, start, 0);

		}
	}



int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);
	addMenu();
	init();
	PlaySound((LPCSTR) "sounds/hello-there.wav", NULL, SND_FILENAME | SND_ASYNC);

	glutKeyboardFunc(keys);
	glutReshapeFunc(fixedSizeReshape);
	glutDisplayFunc(idle);

	glutMainLoop();
	return 0;
}

