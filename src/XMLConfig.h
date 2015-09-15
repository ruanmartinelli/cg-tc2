#ifndef XMLCONFIG_H
#define XMLCONFIG_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include "File.h"

using namespace std;

class XMLConfig{
	private:
		File arena;
	public:
		XMLConfig();
		File getArena();
		void readXML(const char* path);
};

#endif