#include <string>
#include <math.h>
#include <GL/glut.h>
#include "Helicopter.h"
#include "Color.h"
#include "HelicopterConfig.h"

using namespace std;

Helicopter::Helicopter(){}

Helicopter::Helicopter(float velTiro, float velHelicoptero){
	this->velTiro = velTiro;
	this->velHelicoptero = velHelicoptero;
}


void drawBody(){
	glPushMatrix();
		// glTranslatef(40.0,40.0,0.0);
		Rect(0.0, 0.0, bodyWidth, bodyHeight, "green", 1.0, "black", "whatever").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(tailX,tailY,0);
		Rect(0.0, 0.0, tailWidth, tailHeight, "green", 1.0, "black", "whatever").draw();
		glPopMatrix();
}

void Helicopter::drawHelicopter(){
	glPushMatrix();
		glTranslatef(initialX,initialY,0.0);
		drawBody();
	glPopMatrix();
}