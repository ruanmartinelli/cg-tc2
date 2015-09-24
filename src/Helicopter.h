#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"
#include <GL/glut.h>


using namespace std;

class Helicopter{
private:
	float velTiro;
	float velHelicoptero;
	Rect body;
	GLfloat gX;
	GLfloat gY;
public:
	Helicopter();
	Helicopter(float velTiro, float velHelicoptero);
	void drawHelicopter();
	void moveX(GLfloat value);
	void moveY(GLfloat value);
};
#endif