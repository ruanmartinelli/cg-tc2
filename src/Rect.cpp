#include "Rect.h"
#include <GL/glut.h>
#include <string>

using namespace std;

Rect::Rect(){}

Rect::Rect(float x, float y, float width, float height, string fill, float strokeWidth, string stroke, string id){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->fill = fill;
	this->strokeWidth = strokeWidth;
	this->stroke = stroke;
	this->id = id;
}

void Rect::draw(){
	glColor3f (0.6, 0.124, 0.71236723);
	glBegin(GL_QUADS);
		// glVertex2f(r.getX(), r.getY());
		// glVertex2f(r.getX(), r.getHeight());
		// glVertex2f(r.getWidth(), r.getHeight());
		// glVertex2f(r.getWidth(), r.getY());
		glVertex2f(x, y);
		glVertex2f(x, height);
		glVertex2f(width, height);
		glVertex2f(width, y);
	glEnd();

}


float Rect::getX(){
	return this->x;
}
float Rect::getY(){
	return this->y;
}
float Rect::getWidth(){
	return this->width;
}
float Rect::getHeight(){
	return this->height;
}
string Rect::getFill(){
	return this->fill;
}
float Rect::getStrokeWidth(){
	return this->strokeWidth;
}
string Rect::getStroke(){
	return this->stroke;
}
string Rect::getId(){
	return this->id;
}
