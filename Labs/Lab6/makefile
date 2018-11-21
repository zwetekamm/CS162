output: main.o menu.o queue.o
	g++ main.o menu.o queue.o -o lab6

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

queue.o: queue.cpp queue.hpp
	g++ -c queue.cpp

clean:
	rm *.o lab6