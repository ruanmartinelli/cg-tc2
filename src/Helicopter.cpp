#include <string>
#include <math.h>
#include <GL/glut.h>
#include "Helicopter.h"
#include "Utils.h"
#include "HelicopterConfig.h"

using namespace std;

Helicopter::Helicopter(){
	gX = 0.0;
	gY = 0.0;
}

Helicopter::Helicopter(float velTiro, float velHelicoptero){
	this->velTiro = velTiro;
	this->velHelicoptero = velHelicoptero;
	gX = 0.0;
	gY = 0.0;
	cX = cY = 200.0;
	angle = 0.0;
	flying = false;
}

Rect Helicopter::getGun(){
}

void Helicopter::moveX(GLfloat value){
	// this->gX = this->gX + value;
}

void Helicopter::rotate(GLfloat value){
	angle += ((value * 360.0) / (2.0 * 3.1415 * 200.0));
	// angle = angle + value/5;
}

void Helicopter::rotateGun(float value){
	if(fmod((angleGun + value),float(360.0)) < float(45.0) && fmod((angleGun + value),float(360.0)) > float(-45.0)){
		angleGun = angleGun + value*2;
	}
}

void Helicopter::moveY(GLfloat value){
	this->gX += value * cos(( 90 + angle) * 3.1415/180.0);
	this->gY += value * sin((angle + 90) * 3.1415/180.0);
	// cY += value;
}

void Helicopter::setFlying(){
	if(flying){
		flying = false;
	}else{
		flying = true;
	}
}


void drawShots(float sX, float sY, vector<Circle> shots){
		// for(int i = 0; i < shots.size() ; i++){
			// shots.at(i).setCx(shots.at(i).getCx()+1);
			// shots.at(i).setCy(shots.at(i).getCy()+1);
			// float sxTiro = shots.at(i).getSx()/100.0;
			// float syTiro = shots.at(i).getSy()/100.0;

			// shots.at(i).incCx(1.0*sxTiro);
			// shots.at(i).incCy(1.0*syTiro);

			// glPushMatrix();
				// glTranslatef(shots.at(i).getCx(),shots.at(i).getCy(),0.0);
				// shots.at(i).draw();
			// glPopMatrix();
			// cout << "Shot X [" << i << "] = " << shots.at(i).getCx() << endl;
			// cout << "Shot Y [" << i << "] = " << shots.at(i).getCy() << endl; 
			// cout << endl;
		// }
}

void Helicopter::shoot(float x, float y){
	shots.push_back(Circle(0.0, 0.0, 10.0, "blue", "", x, y));
	
}

void drawHelicopter(GLfloat cX, GLfloat cY, GLfloat angle, GLfloat angleHelice, bool flying, float angleGun, vector<Circle> shots){
	if(flying){
		cX = cX/2.0;
		cY = cY/2.0;
	}

	// gun
	glPushMatrix();
		glTranslatef(0.0, -bodyHeight/2.0 +9.0,0.0);
		glRotatef(angleGun-180, 0.0,0.0,1.0);
		Rect(0.0, 0.0, gunWidth, gunHeight, "red", 1.0, "green","").drawTC();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0, 0.0,0.0);
		Rect(0.0, 0.0, bodyWidth, bodyHeight, "green", 1.0, "black","").draw();
	glPopMatrix();


	glPushMatrix();
		glTranslatef(0.0 ,0.0 + bodyHeight,0);
		Rect(0.0, 0.0, tailWidth, tailHeight, "green", 1.0, "black", "").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0 + tailWidth/2.0 + tailRightWidth/2.0,
					0.0 + bodyHeight/2.0 + tailHeight,
					0.0);
		Rect(0.0, 0.0, tailRightWidth, tailRightHeight, "red", 1.0, "black", "").draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0 - tailWidth/2.0 - tailLeftWidth/2.0,
					0.0 + bodyHeight/2.0 + tailHeight,
					0.0);
		Rect(0.0, 0.0, tailLeftWidth, tailLeftHeight, "blue", 1.0, "black", "").draw();
	glPopMatrix();

	//helice 1
	glPushMatrix();
		glTranslatef(0.0, 0.0,0.0);
		glRotatef(angleHelice, 0.0, 0.0,1.0);
		Rect(0.0, 0.0, heliceWidth, heliceHeight, "black", 1.0, "black","").draw();
	glPopMatrix();

	//helice 2
	glPushMatrix();
		glTranslatef(0.0, 0.0 ,0.0);
		glRotatef(angleHelice-90, 0.0, 0.0,1.0);
		Rect(0.0, 0.0, heliceWidth, heliceHeight, "black", 1.0, "black","").draw();
	glPopMatrix();

	//base helice
	glPushMatrix();
		glTranslatef(0.0 ,0.0 ,0);
		Circle(0.0, 0.0, raioHeliceBase, "red", "").draw();
	glPopMatrix();

}

void Helicopter::draw(){
	if(flying){
		angleHelice = angleHelice + 10;
	}
	glPushMatrix();
		// if(!flying) glScalef(1.0/2.0,1.0/2.0,1.0/2.0);
		glTranslatef(cX+gX, cY+gY, 0.0);
		glRotatef(angle, 0.0,0.0,1.0);
		drawHelicopter(cX, cY, angle, angleHelice, flying, angleGun, shots);
	glPopMatrix();

	// if(shots.size() > 0){
	// 	drawShots(1.0, 1.0, shots);
	// }
}


/*void drawHelicopter(GLfloat angleGun, Rect gun, float iX, float iY){
	// cannon
	glPushMatrix();
		glTranslatef(0.0,-bodyHeight/2.0,0);
		glRotatef(angleGun,0.0,0.0,1.0);
		gun = Rect(0.0, 0.0, 0.08, 0.6, "black", 1.0, "black", "");
		gun.draw();
		cout << gun.getStroke() << endl;
	glPopMatrix();

	glPushMatrix();
		body = Rect(body.getX()+xx,  yy+body.getY() ,bodyWidth,bodyHeight, "green", 1.0, "black", "");
		body.draw();

	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailX,tailY,0);
		Rect(0.0, 0.0, tailWidth, tailHeight, "green", 1.0, "black", "").draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailRightX,tailRightY,0);
		Rect(0.0, 0.0, tailRightWidth, tailRightHeight, "red", 1.0, "black", "").draw();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(tailLeftX,tailLeftY,0);
		Rect(0.0, 0.0, tailLeftWidth, tailLeftHeight, "blue", 1.0, "black", "").draw();
	glPopMatrix();

}*/


/*void Helicopter::draw(float gx, float gy){
	glPushMatrix();
		glPushMatrix();
			glTranslatef(initialX+bodyWidth/2.0, initialY+bodyHeight/2.0, 0.0);
			glRotatef(angle, 0.0, 0.0, 1.0);
			drawBody(angleGun, this->gun, this->body, gX, gY);
		glPopMatrix();
	glPopMatrix();
}*/