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
	Circle circ;
	float angle;
	float angleHelicopter;
	float velTiro;
	float angleGun;
public:
	float x, y;
	float xClique, yClique;
	Shot(Circle circ, float x, float y);
	Shot(Circle circ);
	Shot(float x, float y, float angle, float angleHelicopter, float velTiro, float angleGun);
	Shot(Circle circ, float angle);
	float getAngle();
	Circle getCircle();
	void draw();
	void drawEnemyShot(float x, float y);
};
#endif
