#include <string>
#include <math.h>
#include <GL/glut.h>
#include "Helicopter.h"
#include "Utils.h"
#include "HelicopterConfig.h"

using namespace std;

Helicopter::Helicopter(){
	gX = 0.0;
	gY = 0.0;
}

Helicopter::Helicopter(float velTiro, float velHelicoptero){
	this->velTiro = velTiro;
	this->velHelicoptero = velHelicoptero;
}

void Helicopter::moveX(GLfloat value){
	this->gX = this->gX + value;
}

void Helicopter::moveY(GLfloat value){
	this->gY = this->gY + value;
}

void drawBody(){
	glPushMatrix();
		Rect(0.0, 0.0, bodyWidth, bodyHeight, "green", 1.0, "black", "").draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailX,tailY,0);
		Rect(0.0, 0.0, tailWidth, tailHeight, "green", 1.0, "black", "").draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailRightX,tailRightY,0);
		Rect(0.0, 0.0, tailRightWidth, tailRightHeight, "red", 1.0, "black", "").draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailLeftX,tailLeftY,0);
		Rect(0.0, 0.0, tailLeftWidth, tailLeftHeight, "red", 1.0, "black", "").draw();
	glPopMatrix();
}

void Helicopter::drawHelicopter(){
	glPushMatrix();
		glTranslatef(initialX + this->gX,initialY + this->gY, 0.0);
		glScalef(scale, scale, scale);
		drawBody();
	glPopMatrix();
}