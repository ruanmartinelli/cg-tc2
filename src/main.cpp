#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <math.h>
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

	arena.drawArena();

	glutSwapBuffers();
}


void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

		//TODO: modularize

		string click = "";

		float 	postoXBegin = arena.getPostoAbastecimento().getX(),
				postoXEnd = postoXBegin + arena.getPostoAbastecimento().getWidth(),
				postoYBegin = arena.getPostoAbastecimento().getY(),
				postoYEnd = postoYBegin + arena.getPostoAbastecimento().getHeight();

		if(x >= postoXBegin && x <= postoXEnd && y >= postoYBegin && y <= postoYEnd){
			click = arena.getPostoAbastecimento().getId();
		}

		float jogadorDx = (float(x) - arena.getJogador().getCx())*(float(x) - arena.getJogador().getCx());
		float jogadorDy = (y - arena.getJogador().getCy())*(y - arena.getJogador().getCy());
		float jogadorR = arena.getJogador().getR() * arena.getJogador().getR();
		if(jogadorDx + jogadorDy < jogadorR){
			click = arena.getJogador().getId();
		}

		for(int i = 0; i < arena.getInimigos().size(); i++){
			float inimigoDx = (float(x) - arena.getInimigos().at(i).getCx())*(float(x) - arena.getInimigos().at(i).getCx());
			float inimigoDy = (y - arena.getInimigos().at(i).getCy())*(y - arena.getInimigos().at(i).getCy());
			float inimigoR = arena.getInimigos().at(i).getR() * arena.getInimigos().at(i).getR();
			if(inimigoDx + inimigoDy < inimigoR){
				click = arena.getInimigos().at(i).getId();
			}
		}

		for(int i = 0; i < arena.getObjetosResgate().size(); i++){
			float objetoResgateDx = (float(x) - arena.getObjetosResgate().at(i).getCx())*(float(x) - arena.getObjetosResgate().at(i).getCx());
			float objetoResgateDy = (y - arena.getObjetosResgate().at(i).getCy())*(y - arena.getObjetosResgate().at(i).getCy());
			float objetoResgateR = arena.getObjetosResgate().at(i).getR() * arena.getObjetosResgate().at(i).getR();
			if(objetoResgateDx + objetoResgateDy < objetoResgateR){
				click = arena.getObjetosResgate().at(i).getId();
			}
		}

		if(click != "") cout << click << endl;
	}


}

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

