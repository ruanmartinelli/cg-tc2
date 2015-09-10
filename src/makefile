all: clearsc compile
oldcompile:
	g++ src/*.cpp include/tinyxml2/tinyxml2.cpp -lGL -lGLU -lglut
	g++ -otrabalhocg main.cpp

compile:
	g++ -c File.cpp
	g++ -c Arena.cpp
	g++ -c XMLConfig.cpp 
	g++ -c SVG.cpp
	g++ -c Circle.cpp
	g++ -c Rect.cpp
	g++ -c ../include/tinyxml2/tinyxml2.cpp
	g++ -otrabalhocg main.cpp XMLConfig.o File.o SVG.o Rect.o Circle.o tinyxml2.o Arena.o -lGL -lGLU -lglut
	./trabalhocg

run:
	./trabalhocg

clean:
	find . -name '*~' -exec rm {} \; 
	rm trabalhocg

clearsc:
	clear

teste:
	compile run