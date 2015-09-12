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
	public:
		Circle(float cx,float cy,float r,string fill,string id);
		Circle();
		void draw();
		float getCx();
		float getCy();
		float getR();
		string getFill();
		string getId();
	};
#endif