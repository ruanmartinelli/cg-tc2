#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "XMLConfig.h"
#include "File.h"
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

	// arena.getArena().drawRect(arena.getArena());
	arena.drawArena();

	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){cout << x<<endl<<y<<endl;};

int main(int argc, char* argv[]){

	config.readXML("../config/config.xml");

	arena.readXMLArena(config.getArena().getPath().c_str());

	glutInit 				(&argc, argv);
	glutInitDisplayMode 	(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize 		(ARENAX,ARENAY);
	glutInitWindowPosition 	(0, 0);
	glutCreateWindow 	("Arena");
	init 				();
	glutDisplayFunc		(display);
	glutMouseFunc(mouse);
	glutMainLoop		();

}

