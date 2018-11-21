output: mainLab3.o die.o loadedDie.o game.o
	g++ mainLab3.o die.o loadedDie.o game.o -o war

mainLab3.o: mainLab3.cpp
	g++ -c mainLab3.cpp

die.o: die.cpp die.hpp
	g++ -c die.cpp

loadedDie.o: loadedDie.cpp loadedDie.hpp
	g++ -c loadedDie.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

clean:
	rm *.o war
