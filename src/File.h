#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

class File{
	private:
		string name;
		string path;
		string extension;
	public:
		File(string name, string path, string extension);
		File();
		string getName();
		string getPath();
		string getExtension();
		void setName (string n);
		void setPath(string p);
		void setExtension(string ext);
	};
#endif