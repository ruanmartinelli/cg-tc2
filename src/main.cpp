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

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	arena.drawArena();
	// arena.getJogadorHelicopter().drawHelicopter();
	player.drawHelicopter();
	glEnd();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		string message = arena.verifyClick(x, y);
		if(message != "") cout << message; 
	}
}
void idle(){
	if(keys['a'] == 1 || keys['A'] == 1) player.moveX(-1.0); // arena.getJogadorHelicopter().moveX(-100.0); //robo.MoveInX(-1.0);
	if(keys['d'] == 1 || keys['D'] == 1) player.moveX(1.0);  //robo.MoveInX(1.0);
	if(keys['w'] == 1 || keys['W'] == 1) player.moveY(-1.0); //robo.MoveInY(1.0);
	if(keys['s'] == 1 || keys['S'] == 1) player.moveY(1.0); //robo.MoveInY(-1.0);
	glutPostRedisplay();
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
	glutMainLoop		();

}

