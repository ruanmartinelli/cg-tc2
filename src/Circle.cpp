#include "Circle.h"
#include <string>

using namespace std;

Circle::Circle(){}

Circle::Circle(float cx, float cy, float r, string fill, string id){
	this->cx = cx;
	this->cy = cy;
	this->fill = fill;
	this->id = id;
}

float Circle::getCx(){
	return this->cx;
}
float Circle::getCy(){
	return this->cy;
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