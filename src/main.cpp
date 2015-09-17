#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <math.h>
#include <cstring>
#include "XMLConfig.h"
#include "Arena.h"

#define ARENAX arena.getArena().getWidth()
#define ARENAY arena.getArena().getHeight()

using namespace std;

Arena arena;
XMLConfig config;

void init (void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, ARENAX, ARENAY, 0.0, -1.0, 1.0); 
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	arena.drawArena();
	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		string message = arena.verifyClick(x, y);
		//cout << x << ","<< y<< endl;
		if(message != "") cout << message; 
	}
}

int main(int argc, char* argv[]){

	char path[255];

	if(argc != 2){
		cout << "Running at default path './config/config.xml'..." << endl;
		strcpy(path, "../config/config.xml");
	}else{
		strcpy(argv[1],"config.xml");
		strcpy(path, argv[1]);
	}

	config.readXML(path);
	arena.readXMLArena(config.getArena().getPath().c_str());

	glutInit 				(&argc, argv);
	glutInitDisplayMode 	(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize 		(ARENAX,ARENAY);
	glutInitWindowPosition 	(0, 0);
	glutCreateWindow 	("Arena");
	init 				();
	glutDisplayFunc		(display);
	glutMouseFunc		(mouse);
	glutMainLoop		();

}

