#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"
#include "Circle.h"
#include <GL/glut.h>
#include "Shot.h"


using namespace std;

class Helicopter{
private:
	float velTiro;
	float velHelicoptero;
	float cX, cY;
	float angleHelice;
	bool flying;
	vector<Shot> shots;
	float gunX, gunY;
	float velHelice;

	Rect body;
	Rect gun;
	GLfloat gX;
	GLfloat gY;
	GLfloat angle;
	float angleGun;
public:
	Helicopter();
	Helicopter(float velTiro, float velHelicoptero);
	void draw();

	void moveHelice(float value);
	Rect getGun();
	void moveX(GLfloat value);
	void moveY(GLfloat value);
	void rotate(GLfloat value);
	void rotateGun(float value);
	void setFlying();
	float getCurrentAngleGun();
	float getGunPosY();
	float getGunPosX();
	float getAngle();
	float getAngleGun();
	bool getFlying();
	float getVelHelicoptero();

	void draw_gun();
	float getVelTiro();
};
#endif