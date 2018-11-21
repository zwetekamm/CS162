output: mainLab4.o menuL4.o university.o building.o person.o student.o instructor.o
	g++ mainLab4.o menuL4.o university.o building.o person.o student.o instructor.o -o lab4

mainLab4.o: mainLab4.cpp
	g++ -c mainLab4.cpp

menuL4.o: menuL4.cpp menuL4.hpp
	g++ -c menuL4.cpp

university.o: university.cpp university.hpp
	g++ -c university.cpp

building.o: building.cpp building.hpp
	g++ -c building.cpp

person.o: person.cpp person.hpp
	g++ -c person.cpp

student.o: student.cpp student.hpp
	g++ -c student.cpp

instructor.o: instructor.cpp instructor.hpp
	g++ -c instructor.cpp

clean:
	rm *.o lab4
