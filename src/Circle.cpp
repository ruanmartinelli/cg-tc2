#include "Circle.h"
#include <string>
#include <math.h>
#include <GL/glut.h>
#include "Utils.h"

using namespace std;

Circle::Circle(){}

Circle::Circle(float cx, float cy, float r, string fill, string id){
	this->cx = cx;
	this->cy = cy;
	this->fill = fill;
	this->id = id;
	this->r = r;
}

Circle::Circle(float cx,float cy,float r,string fill,string id, float sX, float sY){
	this->cx = cx;
	this->cy = cy;
	this->fill = fill;
	this->id = id;
	this->r = r;
	this->sX = sX;
	this->sY = sY;
}

void Circle::draw(){
	if(fill == "red") glColor3f (red[0],red[1],red[2]);
	if(fill == "green") glColor3f (green[0],green[1],green[2]);
	if(fill == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(fill == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(fill == "white") glColor3f (white[0],white[1],white[2]);
	if(fill == "black") glColor3f (white[0],white[1],white[2]);

	glBegin(GL_TRIANGLE_FAN); 
	for(int i = 0; i < 360; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(360);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);

	} 
	glEnd();

}

void Circle::setCx(float v){
	cx= v;
}
void Circle::setCy(float v){
	cy = v;
}
float Circle::getCx(){
	return this->cx;
}
float Circle::getCy(){
	return this->cy;
}
float Circle::getSx(){
	return this->sX;
}
float Circle::getSy(){
	return this->sY;
}
float Circle::getR(){
	return this->r;
}
string Circle::getFill(){
	return this->fill;
}
string Circle::getId(){
	return this->id;
}
void Circle::incCy(float value){
	cy += value;
}
void Circle::incCx(float value){
	cx += value;
}