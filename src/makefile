all: clearsc compile

compile:
	g++ -c File.cpp
	g++ -c Arena.cpp
	g++ -c XMLConfig.cpp 
	g++ -c Circle.cpp
	g++ -c Rect.cpp
	g++ -c Color.cpp
	g++ -c ../include/tinyxml2/tinyxml2.cpp
	g++ -otrabalhocg main.cpp XMLConfig.o File.o Rect.o Circle.o tinyxml2.o Arena.o Color.o -lGL -lGLU -lglut -lm
	@echo 'Compiling done.'
	@echo 'Type "make run to run on default path.'

run: 
	#path to config.xml goes at the end of next line
	./trabalhocg 

clean:
	find . -name '*~' -exec rm {} \; 
	rm trabalhocg
	rm *.o

clearsc:
	clear

dev: compile run