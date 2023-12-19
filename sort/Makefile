all: performance

performance: performance.o bubble/index.o
	g++ performance.o bubble/index.o -o performance

bubble/index.o: bubble/index.cpp bubble/sort.h
	g++ -c bubble/index.cpp