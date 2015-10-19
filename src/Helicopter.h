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
	bool isEnemy;
	vector<Shot> shots;
	float gunX, gunY;
	float velHelice;
	float tempoDeVoo;
	float freqTiro;
	float arenaX, arenaY; // arena size
	int gas;

	Rect body;
	Rect gun;
	GLfloat gX;
	GLfloat gY;
	GLfloat angle;
	float angleGun;
public:
	Helicopter();
	Helicopter(float freqTiro, float velHelicoptero);
	Helicopter(float velTiro, float velHelicoptero, float tempoDeVoo);
	void draw();
	void drawEnemy();

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
	float getTempoDeVoo();
	bool getFlying();
	float getVelHelicoptero();
	void setArena(float aX, float aY);
	void draw_gun();
	void decGas();
	float getFreqTiro();
	float getVelTiro();
	void setAngle(float a);
	int getGas();
};
#endif
