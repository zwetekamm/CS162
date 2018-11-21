output: main.o readMatrix.o determinant.o menu.o
	g++ main.o readMatrix.o determinant.o menu.o -o output

main.o: main.cpp
	g++ -c main.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

clean:
	rm *.o output
