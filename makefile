#this makefile is a redirect to src/makefile

all: 
	cd src ; \
	make
clean:
	cd src ; \
	make clean
run:
	cd src ; \
	make run