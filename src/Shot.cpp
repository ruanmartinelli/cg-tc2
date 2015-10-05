#include "Shot.h"
#include <math.h>
#include "HelicopterConfig.h"
using namespace std;

Shot::Shot(Circle c, float x, float y){
	this->circ = c;
	this->x = x;
	this->y = y;
}
Shot::Shot(Circle c){
	this->circ = c;
	this->x = 0.0;
	this->y = 0.0;
}

Shot::Shot(float x, float y, float angle, float angleHelicopter, float velTiro, float angleGun){
	this->circ = Circle(0.0, 0.0, 3.0, "blue", "");
	this->velTiro = velTiro;
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->angleHelicopter = angleHelicopter;
	this->angleGun = angleGun;
}

Shot::Shot(Circle c, float ang){
	// this->circ = c;
	// this->x = 0.0;
	// this->y = 0.0;
	// this->angle = ang;
}

void Shot::draw(){
	// cout << angle << endl;
	this->x+= cos((angle -90.0)* 3.1415 / 180.0) * velTiro * 25;
	this->y+= sin((angle -90.0)* 3.1415 / 180.0) * velTiro * 25;

	// cos((player.getAngle() - 90.0) * 3.1415 / 180.0) * 50.0


	glPushMatrix();
		glTranslatef(cos((angleHelicopter - 90.0) * 3.1415 / 180.0) * (bodyHeight/2.0 - 5), sin((angle-angleGun - 90.0) * 3.1415 / 180.0) * (bodyHeight/2.0 - 5),0.0);
		glPushMatrix();
			glTranslatef(this->x, this->y, 0.0);
			Circle(0.0, 0.0, 3.0, "blue", "").draw();
		glPopMatrix();
	glPopMatrix();
}




float Shot::getAngle(){
	return this->angle;
}
Circle Shot::getCircle(){
	return this->circ;
}
