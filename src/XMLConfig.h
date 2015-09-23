#ifndef XMLCONFIG_H
#define XMLCONFIG_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "File.h"
#include "Helicopter.h"

using namespace std;

class XMLConfig{
	private:
		File arena;
	public:
		XMLConfig();
		File getArena();
		void readXML(const char* path);
		Helicopter readHelicopterConfig(const char * path);
};

#endif