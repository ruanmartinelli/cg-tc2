#include <vector>
#include <string>
#include "XMLConfig.h"
#include "File.h"
#include "Helicopter.h"
#include "../include/tinyxml2/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

XMLConfig::XMLConfig(){
}

File XMLConfig::getArena(){
	return this->arena;
}

void XMLConfig::readXML(const char* path){
	XMLDocument doc;	

	doc.LoadFile(path);

	// arquivosDeEntrada
	XMLElement* arquivosDeEntrada = doc.FirstChildElement("aplicacao")->FirstChildElement("arquivosDeEntrada");
	XMLNode* arquivo = arquivosDeEntrada->FirstChild();
	while(arquivo != NULL){

		XMLElement* arq = arquivo->ToElement();

		if(strcmp(arq->Name(),"arquivoDaArena") == 0){
			this->arena = File(arq->Attribute("nome"),
						arq->Attribute("caminho"),
						arq->Attribute("tipo"));
		}

		arquivo = arquivo->NextSibling();
	}

}

Helicopter XMLConfig::readHelicopterConfig(const char * path){
	XMLDocument doc;	

	doc.LoadFile(path);

	XMLElement* helicoptero = doc.FirstChildElement("aplicacao")->FirstChildElement("helicoptero");
	// cout << helicoptero->Attribute("velTiro")<<endl;
	Helicopter h = Helicopter(atof(helicoptero->Attribute("velTiro")), atof(helicoptero->Attribute("velHelicoptero")));
	return h;
}