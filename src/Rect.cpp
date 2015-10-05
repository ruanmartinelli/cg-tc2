#include <GL/glut.h>
#include <string>
#include "Rect.h"
#include "Utils.h"

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
	if(fill == "darkred") glColor3f (darkred[0],darkred[1],darkred[2]);

	/*glVertex2f(-width/2.0, 0.0);
				glVertex2f(-width/2.0, height);
				glVertex2f(width/2.0, height);
				glVertex2f(width/2.0, 0.0);*/

	glBegin(GL_QUADS);
		glVertex2f(-width/2.0, -height/2.0);
		glVertex2f(-width/2.0, height/2.0);
		glVertex2f(width/2.0, height/2.0);
		glVertex2f(width/2.0, -height/2.0);
	glEnd();

	if(stroke == "red") glColor3f (red[0],red[1],red[2]);
	if(stroke == "green") glColor3f (green[0],green[1],green[2]);
	if(stroke == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(stroke == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(stroke == "white") glColor3f (white[0],white[1],white[2]);
	if(stroke == "black") glColor3f (black[0],black[1],black[2]);

	glBegin(GL_LINE_LOOP);
	for(int i = 0 ; i < strokeWidth ; i++){
		glVertex2f(-width/2.0, -height/2.0);
		glVertex2f(-width/2.0, height/2.0);
		glVertex2f(width/2.0, height/2.0);
		glVertex2f(width/2.0, -height/2.0);
		glVertex2f(-width/2.0, -height/2.0);
	}
	glEnd();
}

//bottom center
void Rect::drawTC(){
	if(fill == "red") glColor3f (red[0],red[1],red[2]);
	if(fill == "green") glColor3f (green[0],green[1],green[2]);
	if(fill == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(fill == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(fill == "white") glColor3f (white[0],white[1],white[2]);
	if(fill == "black") glColor3f (black[0],black[1],black[2]);
	if(fill == "darkred") glColor3f (darkred[0],darkred[1],darkred[2]);

	glBegin(GL_QUADS);
		glVertex2f(-width/2.0, 0.0);
				glVertex2f(-width/2.0, height);
				glVertex2f(width/2.0, height);
				glVertex2f(width/2.0, 0.0);
	glEnd();

	if(stroke == "red") glColor3f (red[0],red[1],red[2]);
	if(stroke == "green") glColor3f (green[0],green[1],green[2]);
	if(stroke == "blue") glColor3f (blue[0],blue[1],blue[2]);
	if(stroke == "gray") glColor3f (gray[0],gray[1],gray[2]);
	if(stroke == "white") glColor3f (white[0],white[1],white[2]);
	if(stroke == "black") glColor3f (black[0],black[1],black[2]);

	glBegin(GL_LINE_LOOP);
	for(int i = 0 ; i < strokeWidth ; i++){
		glVertex2f(-width/2.0+i, 0.0+i);
		glVertex2f(-width/2.0+i, height-i);
		glVertex2f(width/2.0-i, height-i);
		glVertex2f(width/2.0-i, 0.0+i);
		glVertex2f(-width/2.0+i, 0.0+i);

		// glVertex2f(x+i, y+i);
		// glVertex2f(x+i, x+height-i);
		// glVertex2f(x+width-i, y+height-i);
		// glVertex2f(x+width-i, y+i);
		// glVertex2f(x+i, y+i);
	}
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
