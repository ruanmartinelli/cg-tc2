#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <math.h>
#include <cstring>
#include "XMLConfig.h"
#include "Arena.h"
#include "Helicopter.h"
#include "Utils.h"

#define ARENAX arena.getArena().getWidth()
#define ARENAY arena.getArena().getHeight()

using namespace std;

Arena arena;
XMLConfig config;
Helicopter player;
float gx = 0.0, gy = 0.0;
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
		arena.drawArena();
		player.draw();
	glEnd();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){
	cout << x << endl;
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		player.setFlying();
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		player.shoot(x, y);
	}
}
void idle(){
	if(keys['a'] == 1 || keys['A'] == 1){
		player.rotate(-5.0); 
		
	} 
	if(keys['d'] == 1 || keys['D'] == 1) player.rotate(5.0);  
	if(keys['w'] == 1 || keys['W'] == 1){
		player.moveY(-5.0); 

		if(keys['a'] == 1 || keys['A'] == 1){
			player.moveX(-5.0);
		}
		if(keys['d'] == 1 || keys['D'] == 1){
			player.moveX(5.0);
		}
	} 
	if(keys['s'] == 1 || keys['S'] == 1){
		player.moveY(5.0);  
		if(keys['a'] == 1 || keys['A'] == 1){
			player.moveX(-5.0);
		}
		if(keys['d'] == 1 || keys['D'] == 1){
			player.moveX(5.0);
		}
	} 
	// if(keys['a'] == 1 || keys['A'] == 1){
	// 	player.moveX(1.0); 
		
	// } 
	// if(keys['d'] == 1 || keys['D'] == 1) player.moveX(-1.0);  
	// if(keys['w'] == 1 || keys['W'] == 1){
	// 	player.moveY(-1.0); 
	// } 
	// if(keys['s'] == 1 || keys['S'] == 1){
	// 	player.moveY(1.0);  
	// } 



	glutPostRedisplay();
}

float mouseX = 0.0;
float mouseY = 0.0;
void motion(int x, int y){
	if(mouseX < x ){
		player.rotateGun(1.0);
	}
	if(mouseX > x ){
		player.rotateGun(-1.0);
	}
	cout << mouseX<<endl;
	mouseX = x;
	mouseY = y;
	//player.rotateGun(1.0);
	// cout << player.getGun().getStroke() << endl;
}

int main(int argc, char* argv[]){

	char path[255];
	if(argc != 2){
		cout << "Running at default path './config/config.xml'..." << endl;
		strcpy(path, "../config/config.xml");
	}else{
		strcpy(path, argv[1]);
		strcat(path, "config.xml");
	}
	config.readXML(path);
	arena.readXMLArena((config.getArena().getPath() + config.getArena().getName() + "." + config.getArena().getExtension()).c_str());
	// arena.setJogadorHelicopter(config.readHelicopterConfig(path));
	player = config.readHelicopterConfig(path);


	glutInit 				(&argc, argv);
	glutInitDisplayMode 	(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize 		(ARENAX,ARENAY);
	glutInitWindowPosition 	(0, 0);
	glutCreateWindow 	("Arena");
	init 				(ARENAX, ARENAY);
	glutDisplayFunc		(display);
	glutMouseFunc		(mouse);
	glutIdleFunc		(idle);
	glutKeyboardFunc 	(setKeyDown);
	glutKeyboardUpFunc 	(setKeyUp);
	glutPassiveMotionFunc(motion);
	glutMainLoop		();

}

