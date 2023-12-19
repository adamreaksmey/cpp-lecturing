all: performance

performance: performance.o bubble/index.o
	g++ performance.o bubble/index.o -o performance

performance.o: performance.cpp bubble/sort.h
	g++ -c performance.cpp

bubble/index.o: bubble/index.cpp bubble/sort.h
	g++ -c bubble/index.cpp
	
LIBS += quick/sort.o