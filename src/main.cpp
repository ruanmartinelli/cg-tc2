#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "XMLConfig.h"
#include "File.h"
#include "Arena.h"

#define WIN_X 500.0
#define WIN_Y 500.0
#define ARENAX arena.getArena().getWidth()
#define ARENAY arena.getArena().getHeight()


using namespace std;

Arena arena;
XMLConfig config;


void init (void){
	glClearColor (0.1, 0.5, 0.0, 0.6);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, ARENAX, ARENAY, 0.0, -1.0, 1.0); 
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

int main(int argc, char* argv[]){

	config.readXML("../config/config.xml");

	arena.readXMLArena(config.getArena().getPath().c_str());


	// cout << arena.getJogador().getFill() << endl;
	// cout << arena.getArena().getWidth()<< endl;

	glutInit 				(&argc, argv);
	glutInitDisplayMode 	(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize 		(ARENAX,ARENAY);
	glutInitWindowPosition 	(100, 100);
	glutCreateWindow 	("Arena");
	init 				();
	glutDisplayFunc		(display);
	// glutMouseFunc		(mouse);
	// glutMotionFunc		(drag);
	glutMainLoop		();

	//arena.Draw();


	// cout << config.getFiles().at(0).getExtension() << endl;
	// cout << config.getFiles().at(0).getPath() << endl;

	// if(config.getFiles().at(0).getExtension() == "svg"){
	// 	SVG svg;
	// 	svg.readSVG(config.getFiles().at(0).getPath());
	// }

	// SVG svg;
	// svg.readSVG(config.getFiles().at(0).getPath().c_str());

	//svg is read at this point

	// cout << svg.getCircles().size() << endl;

}

