#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"


using namespace std;

class Helicopter{
private:
	float velTiro;
	float velHelicoptero;
	Rect body;
public:
	Helicopter();
	Helicopter(float velTiro, float velHelicoptero);
	void drawHelicopter();
};
#endif