output: mainFileIO.o fileIO.o
	g++ mainFileIO.o fileIO.o -o runLab2

mainFileIO.o: mainFileIO.cpp
	g++ -c mainFileIO.cpp

fileIO.o: fileIO.cpp fileIO.hpp
	g++ -c fileIO.cpp

clean:
	rm *.o runLab2
	
