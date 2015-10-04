#ifndef SHOT_H
#define SHOT_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Circle.h"
#include <GL/glut.h>


using namespace std;

class Shot{
private:
	Circle circ;
	float angle;
	float angleHelicopter;
	float velTiro;
public:
	float x, y;
	float xClique, yClique;
	Shot(Circle circ, float x, float y);
	Shot(Circle circ);
	Shot(float x, float y, float angle, float angleHelicopter, float velTiro);
	Shot(Circle circ, float angle);
	float getAngle();
	Circle getCircle();
	void draw();
};
#endif