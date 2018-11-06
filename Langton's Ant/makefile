output: main.o menu.o ant.o
	g++ main.o menu.o ant.o -o ant

mainAnt.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp
clean:
	rm *.o ant
