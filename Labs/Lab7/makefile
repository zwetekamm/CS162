output: main.o menu.o queue.o stack.o
	g++ main.o menu.o queue.o stack.o -o lab7

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

queue.o: queue.cpp queue.hpp
	g++ -c queue.cpp

stack.o: stack.cpp stack.hpp
	g++ -c stack.cpp

clean:
	rm *.o lab7