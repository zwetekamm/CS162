output: main.o recursion.o menu.o
	g++ main.o recursion.o menu.o -o lab5

main.o: main.cpp
	g++ -c main.cpp

recursion.o: recursion.cpp recursion.hpp
	g++ -c recursion.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

clean:
	rm *.o lab5	
