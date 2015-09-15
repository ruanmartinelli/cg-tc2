#ifndef ARENA_H
#define AREHA_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "Rect.h"
#include "Circle.h"

using namespace std;

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
		string verifyClick(int x, int y);
};

#endif