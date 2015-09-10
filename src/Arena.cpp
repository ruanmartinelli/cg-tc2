#include <string>
#include <vector>
#include "Arena.h"
#include "../include/tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

Arena::Arena(){}

Rect Arena::getArena(){
	return this->arena;
}
Rect Arena::getPostoAbastecimento(){
	return this->postoAbastecimento;
}
Circle Arena::getJogador(){
	return this->jogador;
}

void Arena::readXMLArena(const char* path){
	XMLDocument doc;
	doc.LoadFile(path);

	XMLNode* svgObjs = doc.FirstChildElement("svg")->FirstChild();
	while(svgObjs != NULL){

		/*Rect arena;
		Rect postoAbastecimento;
		Circle jogador;
		vector<Circle> inimigos;
		vector<Circle> objetosResgate;*/
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

		if(strcmp(obj->Attribute("id"),"ObjetosRestate") == 0){
			this->objetosResgate.push_back(Circle(	atof(obj->Attribute("cx")), 
													atof(obj->Attribute("cy")), 
													atof(obj->Attribute("r")), 
													obj->Attribute("fill"), 
													obj->Attribute("id")));
		}

		svgObjs = svgObjs->NextSibling();
	}
}

