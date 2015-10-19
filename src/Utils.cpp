#include "Utils.h"
#include <string>
#include <GL/glut.h>

const float red[] = {1.0,0.0,0.0};
const float blue[] = {0.0,0.0,1.0};
const float green[] = {0.0,1.0,0.0};
const float gray[] = {0.5,0.5,0.5};
const float white[] = {1.0,1.0,1.0};
const float black[] = {0.0,0.0,0.0};
const float darkred[] = {0.8,0.0,0.0};
const float darkgreen[] = {0.0,0.8,0.0};

int keys[256];

void init (float arenaX, float arenaY){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, arenaX, arenaY, 0.0, -1.0, 1.0);
}

// true = victory
// false = defeat
bool checkDefeat(Helicopter player, float x, float y){
	string defeat = "DEFEAT";
	if(player.getGas() <= 0){
	// if(player.getGas() >10){
			glPushMatrix();
				glTranslatef(x, y, 0.0);
				glColor3f(0.0, 0.0, 0.0);
				glScalef(0.5, 0.5, 0.5);
				glRotatef(180.0, 1.0, 0.0, 0.0);
				for(int i = 0; i < 6 ; i++) glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,defeat[i]);
			glPopMatrix();
		return true;
	}
	return false;
}

void setKeyUp(unsigned char key, int x, int j){

	switch(key){
		case 'a': case 'A':	keys['a'] = 0; break;
		case 'D': case 'd':	keys['d'] = 0; break;
		case 'w': case 'W': keys['w'] = 0; break;
		case 'S': case 's': keys['s'] = 0; break;
		case '+': keys['+'] = 0; break;
		case '-': keys['-'] = 0; break;
		break;
	}
	glutPostRedisplay();
}

void setKeyDown(unsigned char key, int x, int j){
	switch(key){
		case 'a': case 'A':	keys['a'] = 1; break;
		case 'D': case 'd':	keys['d'] = 1; break;
		case 'w': case 'W': keys['w'] = 1; break;
		case 'S': case 's': keys['s'] = 1; break;
		case '+': keys['+'] = 1; break;
		case '-': keys['-'] = 1; break;
		break;
	}
	glutPostRedisplay();
}
