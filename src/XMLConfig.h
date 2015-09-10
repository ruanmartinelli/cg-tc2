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
		// svector<File> files;
		File arena;
	public:
		// vector<File> getFiles();
		// void addFile(File f);
		XMLConfig();
		File getArena();
		void readXML(const char* path);
};

#endif