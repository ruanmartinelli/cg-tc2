#include <string>
#include <vector>
#include "Arena.h"
#include "../include/tinyxml2/tinyxml2.h"
#include "Helicopter.h"

using namespace std;
using namespace tinyxml2;

Arena::Arena(){}

void Arena::drawArena(float x, float y){
	glPushMatrix();
		glTranslatef(x/2.0, y/2.0,0.0);
		// arena
		arena.draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(postoAbastecimento.getX() + postoAbastecimento.getWidth()/2.0,
			postoAbastecimento.getY() + postoAbastecimento.getHeight()/2.0,0.0);
		postoAbastecimento.draw();
	glPopMatrix();
	// jogador.draw();
	// jogadorHelicopter.drawHelicopter();

	for(int i = 0; i < inimigos.size() ; i++){
		// inimigos.at(i).draw();
	}

	for(int j = 0; j < objetosResgate.size() ; j++){
		 objetosResgate.at(j).draw();
	}
}

Rect Arena::getArena(){
	return this->arena;
}

Rect Arena::getPostoAbastecimento(){
	return this->postoAbastecimento;
}

Circle Arena::getJogador(){
	return this->jogador;
}

vector<Circle> Arena:: getInimigos(){
	return this->inimigos;
}

vector<Circle> Arena::getObjetosResgate(){
	return this->objetosResgate;
}

string Arena::verifyClick(int x, int y){
	string click;
	float 	postoXBegin = getPostoAbastecimento().getX(),
			postoXEnd = postoXBegin + getPostoAbastecimento().getWidth(),
			postoYBegin = getPostoAbastecimento().getY(),
			postoYEnd = postoYBegin + getPostoAbastecimento().getHeight();

	if(x >= postoXBegin && x <= postoXEnd && y >= postoYBegin && y <= postoYEnd){
		click = getPostoAbastecimento().getId() + "\n" + click ;
	}

	float jogadorDx = (float(x) - getJogador().getCx())*(float(x) - getJogador().getCx());
	float jogadorDy = (y - getJogador().getCy())*(y - getJogador().getCy());
	float jogadorR = getJogador().getR() * getJogador().getR();
	if(jogadorDx + jogadorDy < jogadorR){
		click =  getJogador().getId() + "\n" + click;
	}

	for(int i = 0; i < getInimigos().size(); i++){
		float inimigoDx = (float(x) - getInimigos().at(i).getCx())*(float(x) - getInimigos().at(i).getCx());
		float inimigoDy = (y - getInimigos().at(i).getCy())*(y - getInimigos().at(i).getCy());
		float inimigoR = getInimigos().at(i).getR() * getInimigos().at(i).getR();
		if(inimigoDx + inimigoDy < inimigoR){
			click = getInimigos().at(i).getId() + "\n" + click;
		}
	}

	for(int i = 0; i < getObjetosResgate().size(); i++){
		float objetoResgateDx = (float(x) - getObjetosResgate().at(i).getCx())*(float(x) - getObjetosResgate().at(i).getCx());
		float objetoResgateDy = (y - getObjetosResgate().at(i).getCy())*(y - getObjetosResgate().at(i).getCy());
		float objetoResgateR = getObjetosResgate().at(i).getR() * getObjetosResgate().at(i).getR();
		if(objetoResgateDx + objetoResgateDy < objetoResgateR){
			click = getObjetosResgate().at(i).getId() + "\n" + click;
		}
	}
	return click;
}

void Arena::readXMLArena(const char* path){
	XMLDocument doc;
	doc.LoadFile(path);

	XMLNode* svgObjs = doc.FirstChildElement("svg")->FirstChild();
	while(svgObjs != NULL){

		XMLElement * obj = svgObjs->ToElement();

		if(strcmp(obj->Attribute("id"),"Arena") == 0){
			this->arena = Rect(	atof(obj->Attribute("x")),
												atof(obj->Attribute("y")),
												atof(obj->Attribute("width")),
												atof(obj->Attribute("height")),
												obj->Attribute("fill"),
												atof(obj->Attribute("stroke-width")),
												obj->Attribute("stroke"),
												obj->Attribute("id"));
		}

		if(strcmp(obj->Attribute("id"),"PostoAbastecimento") == 0){
			this->postoAbastecimento = Rect(	atof(obj->Attribute("x")),
												atof(obj->Attribute("y")),
												atof(obj->Attribute("width")),
												atof(obj->Attribute("height")),
												obj->Attribute("fill"),
												atof(obj->Attribute("stroke-width")),
												obj->Attribute("stroke"),
												obj->Attribute("id"));
		}

		if(strcmp(obj->Attribute("id"),"Jogador") == 0){
			this->jogador = Circle(	atof(obj->Attribute("cx")),
									atof(obj->Attribute("cy")),
									atof(obj->Attribute("r")),
									obj->Attribute("fill"),
									obj->Attribute("id"));
		}

		if(strcmp(obj->Attribute("id"),"Inimigo") == 0){
			this->inimigos.push_back(Circle(	atof(obj->Attribute("cx")),
													atof(obj->Attribute("cy")),
													atof(obj->Attribute("r")),
													obj->Attribute("fill"),
													obj->Attribute("id")));
		}

		if(strcmp(obj->Attribute("id"),"ObjetoResgate") == 0){
			this->objetosResgate.push_back(Circle(	atof(obj->Attribute("cx")),
													atof(obj->Attribute("cy")),
													atoi(obj->Attribute("r")),
													obj->Attribute("fill"),
													obj->Attribute("id")));
		}

		svgObjs = svgObjs->NextSibling();
	}
}
