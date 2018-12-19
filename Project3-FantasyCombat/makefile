output: main.o menu.o game.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o
	g++ main.o menu.o game.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o -o fantasycombat

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

character.o: character.cpp character.hpp
	g++ -c character.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -c vampire.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c barbarian.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	g++ -c bluemen.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c medusa.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	g++ -c harrypotter.cpp

clean:
	rm *.o fantasycombat
