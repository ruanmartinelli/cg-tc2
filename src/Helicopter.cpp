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
	gX = 0.0;
	gY = 0.0;
	cX = initialX;
	cY = initialY;
	angle = 0.0;
	flying = false;
	velHelice = 0.0;
}

float Helicopter::getVelTiro(){
	return this->velTiro;
}

float Helicopter::getVelHelicoptero(){
	return this->velHelicoptero;
}

Rect Helicopter::getGun(){
}

float Helicopter::getCurrentAngleGun(){

	return angleGun + angle;
}

float Helicopter::getGunPosX(){

	return (cX + gX);
}

float Helicopter::getGunPosY(){

	return cY + gY;
}

float Helicopter::getAngle(){

	return angle;
}

float Helicopter::getAngleGun(){

	return angleGun;
}

bool Helicopter::getFlying(){

	return flying;
}

void Helicopter::moveX(GLfloat value){
}

void Helicopter::rotate(GLfloat value){
	
	angle += ((value * 360.0) / (2.0 * 3.1415 * 200.0));
}

void Helicopter::moveHelice(float value){
	
	velHelice += value;
}

void Helicopter::moveY(GLfloat value){
	if(flying){
		this->gX += value * cos(( 90 + angle) * 3.1415/180.0);
		this->gY += value * sin((angle + 90) * 3.1415/180.0);
	}
}

void Helicopter::setFlying(){
	if(flying){
		flying = false;
	}else{
		flying = true;
	}
}

void Helicopter::rotateGun(float value){
	if(fmod((angleGun + value),float(360.0)) < float(45.0) && fmod((angleGun + value),float(360.0)) > float(-45.0)){
		angleGun = angleGun + value;
	}
}

void drawGun(float angleGun, float gunx, float guny, float angle){
	glPushMatrix();
		glTranslatef(gunx, guny,0.0);
		glRotatef(angleGun-180,0.0,0.0,1.0);
		Rect(0.0, 0.0, gunWidth, gunHeight, "black", 1.0, "black","").drawTC();
	glPopMatrix();
}

void drawHelicopter(GLfloat cX, GLfloat cY, GLfloat angle, GLfloat angleHelice, bool flying, float angleGun){
	if(flying){
		cX = cX/2.0;
		cY = cY/2.0;
	}

	glPushMatrix();
		glTranslatef(0.0, 0.0,0.0);
		Rect(0.0, 0.0, bodyWidth, bodyHeight, "darkred", 1.0, "black","").draw();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.0 ,0.0 + bodyHeight,0);
		Rect(0.0, 0.0, tailWidth, tailHeight, "darkred", 1.0, "black", "").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0 + tailWidth/2.0 + tailRightWidth/2.0,
					0.0 + bodyHeight/2.0 + tailHeight,
					0.0);
		Rect(0.0, 0.0, tailRightWidth, tailRightHeight, "black", 1.0, "black", "").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0 - tailWidth/2.0 - tailLeftWidth/2.0,
					0.0 + bodyHeight/2.0 + tailHeight,
					0.0);
		Rect(0.0, 0.0, tailLeftWidth, tailLeftHeight, "black", 1.0, "black", "").draw();
	glPopMatrix();

	//helice 1
	glPushMatrix();
		glTranslatef(0.0, 0.0,0.0);
		glRotatef(angleHelice, 0.0, 0.0,1.0);
		Rect(0.0, 0.0, heliceWidth, heliceHeight, "black", 1.0, "black","").draw();
	glPopMatrix();

	//helice 2
	glPushMatrix();
		glTranslatef(0.0, 0.0 ,0.0);
		glRotatef(angleHelice-90, 0.0, 0.0,1.0);
		Rect(0.0, 0.0, heliceWidth, heliceHeight, "black", 1.0, "black","").draw();
	glPopMatrix();

	//base helice
	glPushMatrix();
		glTranslatef(0.0 ,0.0 ,0);
		Circle(0.0, 0.0, raioHeliceBase, "gray", "").draw();
	glPopMatrix();
}

void Helicopter::draw(){
	if(flying){
		angleHelice = angleHelice + velHelice + 1.0;
	}

	//helicopter
	glPushMatrix();
		glTranslatef(cX+gX, cY+gY, 0.0);
		glRotatef(angle, 0.0,0.0,1.0);
		if(!flying) glScalef(1.0/1.5,1.0/1.5,1.0/1.5);
		drawGun(angleGun, 0.0, -bodyHeight/2.0 + 5.0, angle); 
		drawHelicopter(cX, cY, angle, angleHelice, flying, angleGun);
	glPopMatrix();
	
}


