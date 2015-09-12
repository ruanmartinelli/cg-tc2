#ifndef ARENA_H
#define AREHA_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"
#include "Circle.h"

using namespace std;


//   <rect x="0" y="0" width="800" height="700" fill="white" stroke-width="4" stroke="black" id="Arena"/>
//   <rect x="50" y="50" width="100" height="200" fill="gray" stroke-width="4" stroke="black" id="PostoAbastecimento" />
//   <circle cx="125" cy="125" r="30" fill="green" id="Jogador" />
//   <circle cx="625" cy="125" r="30" fill="red" id="Inimigo" />
//   <circle cx="125" cy="525" r="30" fill="red" id="Inimigo" />
//   <circle cx="325" cy="325" r="30" fill="red" id="Inimigo" />
//   <circle cx="625" cy="625" r="30" fill="blue" id="ObjetoResgate" />
//   <circle cx="225" cy="525" r="30" fill="blue" id="ObjetoResgate" />

class Arena{
	private:
		Rect arena;
		Rect postoAbastecimento;
		Circle jogador;
		vector<Circle> inimigos;
		vector<Circle> objetosResgate;
	public:
		Arena();
		void readXMLArena(const char* path);
		Rect getArena();
		Rect getPostoAbastecimento();
		Circle getJogador();
		void drawArena();
		vector<Circle> getInimigos();
		vector<Circle> getObjetosResgate();
};

#endif