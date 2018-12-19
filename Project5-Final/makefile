output.o: main.o menu.o game.o player.o item.o space.o home.o basement.o van.o crosswalk.o park.o concert.o
	g++ main.o menu.o game.o player.o item.o space.o home.o basement.o van.o crosswalk.o park.o concert.o -o final

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

player.o: player.cpp player.hpp
	g++ -c player.cpp

item.o: item.cpp item.hpp
	g++ -c item.cpp

space.o: space.cpp space.hpp
	g++ -c space.cpp

home.o: home.cpp home.hpp
	g++ -c home.cpp

basement.o: basement.cpp basement.hpp
	g++ -c basement.cpp

van.o: van.cpp van.hpp
	g++ -c van.cpp

crosswalk.o: crosswalk.cpp crosswalk.hpp
	g++ -c crosswalk.cpp

park.o: park.cpp park.hpp
	g++ -c park.cpp

concert.o: concert.cpp concert.hpp
	g++ -c concert.cpp

clean:
	rm *.o