#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

// <circle cx="325" cy="325" r="30" fill="red" id="Inimigo" />
class Circle{
	private:
		float 	cx;
		float 	cy;
		float 	r;
		string 	fill;
		string 	id;
		float sX, sY;
	public:
		Circle(float cx,float cy,float r,string fill,string id);
		Circle(float cx,float cy,float r,string fill,string id, float sX, float sY);
		Circle();
		void draw();
		float getCx();
		float getCy();
		float getSx();
		float getSy();
		float getR();
		string getFill();
		string getId();
		void setCx(float v);
		void setCy(float v);
		void incCx(float value);
		void incCy(float value);
	};
#endif