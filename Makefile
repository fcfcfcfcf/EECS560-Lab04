Lab04: main.o Executive.o Node.o
	g++ -std=c++11 -g -Wall main.o Executive.o Node.o -o Lab04

main.o: main.cpp Executive.h Node.h 
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Node.h HashTableChained.h HashTableChained.hpp HashTableQP.h HashTableQP.hpp HashTableDH.h HashTableDH.hpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o Lab04