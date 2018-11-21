output: mainZoo.o menu.o game.o animal.o tiger.o penguin.o turtle.o
	g++ mainZoo.o menu.o game.o animal.o tiger.o penguin.o turtle.o -o zoo

mainZoo.o: mainZoo.cpp
	g++ -c mainZoo.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

clean:
	rm *.o zoo
