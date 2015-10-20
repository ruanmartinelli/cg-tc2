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

// enemy
Helicopter::Helicopter(float freqTiro, float velHelicoptero, float cx, float cy){
	isEnemy 				= true;
	this->velTiro 			= 0.2;
	this->freqTiro 			= freqTiro;
	this->velHelicoptero 	= velHelicoptero;
	gX 			= 0.0,
	gY 			= 0.0;
	radius 		= bodyWidth;
	cX = cx;
	cY = cy;
	// cX 			= rand() % 800 - radius,
	// cY 			= rand() % 600 - radius;
	// cX = radius + (rand() % (int)(700 - radius + 1));
	// cY = radius + (rand() % (int)(600 - radius + 1));
	angle 		= rand() % 360;
	// angle = 90;
	flying 		= true;
	velHelice 	= 10.0;
	this->collided = false;
}

// player
Helicopter::Helicopter(float velTiro, float velHelicoptero, float tempoDeVoo){
	isEnemy 				= false;
	this->velTiro 			= velTiro;
	this->velHelicoptero 	= velHelicoptero;
	this->tempoDeVoo 		= tempoDeVoo;
	gas 					= tempoDeVoo;
	gX 			= 0.0;
	gY 			= 0.0;
	cX 			= initialX;
	cY 			= initialY;
	angle 		= 0.0;
	flying 		= false;
	velHelice 	= 0.0;
	radius 		= bodyWidth;
	this->collided = false;
}

float Helicopter::getFreqTiro()			{return this->freqTiro;}
float Helicopter::getVelTiro()			{return this->velTiro;}
float Helicopter::getVelHelicoptero()	{return this->velHelicoptero;}
float Helicopter::getCurrentAngleGun()	{return angleGun + angle;}
float Helicopter::getGunPosX()			{return cX + gX;}
float Helicopter::getGunPosY()			{return cY + gY;}
float Helicopter::getAngle()			{return angle;}
float Helicopter::getAngleGun()			{return angleGun;}
bool Helicopter::getFlying()			{return flying;}
float Helicopter::getTempoDeVoo()		{return this->tempoDeVoo;}
void Helicopter::moveX(GLfloat value)	{}
void Helicopter::setAngle(float a)		{this->angle = a;}
int Helicopter::getGas()				{return this->gas;};
void Helicopter::setGas(float g)		{this->gas = g;};
float Helicopter::getRadius()			{return this->radius;};
float Helicopter::getGx()				{return this->gX;};
float Helicopter::getCx()				{return this->cX;};
float Helicopter::getGy()				{return this->gY;};
float Helicopter::getCy()				{return this->cY;};
void Helicopter::setCollided(bool value){this->collided = value;};
bool Helicopter::getCollided()			{return this->collided;};
float Helicopter::getNextMoveX( float val ){
	return this->gX + val * cos(( 90 + angle) * 3.1415/180.0);
}
float Helicopter::getNextMoveY( float val ){
	return this->gY + val * sin(( 90 + angle) * 3.1415/180.0);
}
void Helicopter::rotate(GLfloat value){
	angle += value;
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
void Helicopter::setArena(float aX, float aY){
	this->arenaX = aX;
	this->arenaY = aY;
}
void Helicopter::rotateGun(float value){
	if(fmod((angleGun + value),float(360.0)) < float(45.0) && fmod((angleGun + value),float(360.0)) > float(-45.0)){
		angleGun = angleGun + value;
	}
}
void Helicopter::decGas(){
	cout << "[INFO] Gas level: "<< gas <<endl;
	this->gas--;
}
void drawGun(float angleGun, float gunx, float guny, float angle){
	glPushMatrix();
		glTranslatef(gunx, guny,0.0);
		glRotatef(angleGun-180,0.0,0.0,1.0);
		Rect(0.0, 0.0, gunWidth, gunHeight, "black", 1.0, "black","").drawTC();
	glPopMatrix();
}

void drawHelicopter(GLfloat cX, GLfloat cY, GLfloat angle, GLfloat angleHelice, bool flying, float angleGun, bool isEnemy){
	if(flying){
		cX = cX/2.0;
		cY = cY/2.0;
	}

	glPushMatrix();
		glTranslatef(0.0, 0.0,0.0);
		if(isEnemy) Rect(0.0, 0.0, bodyWidth, bodyHeight, "darkred", 1.0, "black","").draw();
		if(!isEnemy)Rect(0.0, 0.0, bodyWidth, bodyHeight, "darkgreen", 1.0, "black","").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0 ,0.0 + bodyHeight,0);
		if(isEnemy) Rect(0.0, 0.0, tailWidth, tailHeight, "darkred", 1.0, "black", "").draw();
		if(!isEnemy)Rect(0.0, 0.0, tailWidth, tailHeight, "darkgreen", 1.0, "black", "").draw();

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

void drawGas(int gas, int tempoDeVoo, float arenaX, float arenaY){
	glPushMatrix();
		if(gas >= 0){
			glTranslatef(arenaX - (arenaX/100 * 5) ,(arenaY/100*5) + tempoDeVoo * 10,0.0);
			glRotatef(180 ,0.0 ,0.0 ,1.0);
			Rect(0.0, 0.0, 40.0, tempoDeVoo * 10, "blue", 1.0, "black","").drawGasBar();
			glTranslatef(0.0, (gas -1) *10,0.0);
			Rect(0.0,0.0,50.0,10.0,"",0.0,"","").drawGasIndicator();
		}
	glPopMatrix();
}

void Helicopter::draw(){
	if(flying) angleHelice = angleHelice + velHelice + 1.0;
	// helicopter
	glPushMatrix();
		glTranslatef(cX+gX, cY+gY, 0.0);
		glRotatef(angle, 0.0,0.0,1.0);
		if(!flying) glScalef(1.0/1.5,1.0/1.5,1.0/1.5);
		drawGun(angleGun, 0.0, -bodyHeight/2.0 + 5.0, angle);
		drawHelicopter(cX, cY, angle, angleHelice, flying, angleGun, isEnemy);
	glPopMatrix();

	// gas
	if(!isEnemy && flying){
		glPushMatrix();
			drawGas(gas,tempoDeVoo, arenaX, arenaY);
		glPopMatrix();
	}
}
