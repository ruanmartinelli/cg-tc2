all: clearsc compile

compile:
	g++ -c File.cpp
	g++ -c Arena.cpp
	g++ -c XMLConfig.cpp
	g++ -c Circle.cpp
	g++ -c Rect.cpp
	g++ -c Utils.cpp
	g++ -c Helicopter.cpp
	g++ -c Shot.cpp
	g++ -c ../include/tinyxml2/tinyxml2.cpp
	g++ -otrabalhocg main.cpp XMLConfig.o File.o Rect.o Circle.o tinyxml2.o Arena.o Utils.o Helicopter.o Shot.o -lGL -lGLU -lglut -lm

run:
	./trabalhocg #insert path to config.xml here

clean:
	find . -name '*~' -exec rm {} \;
	rm *.o
	rm trabalhocg

clearsc:
	clear

dev: clearsc compile run
