#include "File.h"
#include <string>

using namespace std;

File::File(){}

File::File(string name, string path, string extension){
	this->name = name;
	this->path = path;
	this->extension = extension;
}

string File::getName(){
	return name;
}
string File::getPath(){
	return path;
}
string File::getExtension(){
	return extension;
}
void File::setName (string n){
	name = n;
}
void File::setPath(string p){
	path = p;
}
void File::setExtension(string ext){
	extension = ext;
}