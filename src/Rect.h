#ifndef RECT_H
#define RECT_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

class Rect{
	private:
		float x;
		float y;
		float width;
		float height;
		string fill;
		float strokeWidth;
		string stroke;
		string id;
	public:
		Rect(float x, float y, float width, float height, string fill, float strokeWidth, string stroke, string id);
		Rect();

		void draw();
		void drawTC();
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		string getFill();
		float getStrokeWidth();
		string getStroke();
		string getId();
	};
#endif