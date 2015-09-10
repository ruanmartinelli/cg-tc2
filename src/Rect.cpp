#include "Rect.h"
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
