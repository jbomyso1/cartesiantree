all:main

main: main.o
	g++ -std=c++11 -g main.o -o main

main.o: main.cpp cartesian.h node.h
	g++ -std=c++11 -g -c main.cpp

clean:
	rm *.0 *~ main
