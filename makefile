all: clear compile
compile:
	g++ src/*.cpp include/tinyxml2/tinyxml2.cpp -lGL -lGLU -lglut
	g++ -otrabalhocg main.cpp

wincompile:
	g++ -c XMLConfig.cpp 
	g++ -c File.cpp
	g++ -otrabalhocg main.cpp XMLConfig.o File.o
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