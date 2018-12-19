CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -Wall
#CXXFLAGS += -03
#LDFLAGS = -lboost_date_time

output:	main.o getValidData.o readMenu.o Ant.o Doodlebug.o Critter.o Grid.o  
	$(CXX) $(LDFLAGS) main.o getValidData.o readMenu.o Ant.o Doodlebug.o Critter.o Grid.o -o output

main.o:	main.cpp Grid.hpp getValidData.hpp readMenu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

getValidData.o: getValidData.cpp
	$(CXX) $(CXXFLAGS) -c getValidData.cpp

readMenu.o: readMenu.cpp getValidData.hpp
	$(CXX) $(CXXFLAGS) -c readMenu.cpp

Ant.o: Ant.cpp Ant.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Doodlebug.cpp

Critter.o: Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Critter.cpp

Grid.o: Grid.cpp Grid.hpp Critter.hpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

clean:
	rm *.o output
