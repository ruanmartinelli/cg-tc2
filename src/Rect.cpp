#include <GL/glut.h>
#include <string>
#include "Rect.h"
#include "Color.h"

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
	if(fill == "red") glColor3f (red[0],red[1],red[2]);
	if(fill == "green") glColor3f (green[0],green[1],green[2]);
	if(fill == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(fill == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(fill == "white") glColor3f (white[0],white[1],white[2]);
	if(fill == "black") glColor3f (black[0],black[1],black[2]);

	glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x, x+height);
		glVertex2f(x+width, y+height);
		glVertex2f(x+width, y);
	glEnd();

	// TODO: Draw stroke

	if(stroke == "red") glColor3f (red[0],red[1],red[2]);
	if(stroke == "green") glColor3f (green[0],green[1],green[2]);
	if(stroke == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(stroke == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(stroke == "white") glColor3f (white[0],white[1],white[2]);
	if(stroke == "black") glColor3f (black[0],black[1],black[2]);

	glLineWidth((GLfloat)strokeWidth);
	glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x, x+height);
		glVertex2f(x+width, y+height);
		glVertex2f(x+width, y);
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
