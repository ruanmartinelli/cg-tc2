#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"
#include "Circle.h"
#include <GL/glut.h>


using namespace std;

class Helicopter{
private:
	float velTiro;
	float velHelicoptero;
	float cX, cY;
	float angleHelice;
	bool flying;
	vector<Circle> shots;

	Rect body;
	Rect gun;
	GLfloat gX;
	GLfloat gY;
	GLfloat angle;
	float angleGun;
public:
	Helicopter();
	Helicopter(float velTiro, float velHelicoptero);
	// void drawHelicopter(float gx, float gy);
	void draw();
	void shoot(float x, float y);

	Rect getGun();
	void moveX(GLfloat value);
	void moveY(GLfloat value);
	void rotate(GLfloat value);
	void rotateGun(float value);
	void setFlying();
};
#endif