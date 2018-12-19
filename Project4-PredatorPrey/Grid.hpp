/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - Grid.hpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the specification file for the class Grid. It
 *               represents a 2D grid of Ants, Doodlebugs, and blank spaces.
 *               It has functions to call these critters to move, breed,
 *               and starve. It also has functions to add a time step and
 *               print out the current state of the Grid.
 ************************************************************************/
#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include "Ant.hpp"
#include "Doodlebug.hpp"

class Grid
{
   private:
   //Members variables
   int numRows;
   int numColumns;
   Critter*** critterArr;

   //Private functions to check array bounds and possible ways to move
   bool getBreedDirections(int row, int col, Directions* validDir, int &numDir);
   void getMoveDirection(int row, int col, Directions &dir, int &numDir);
   bool getValidAnts(int row, int col, Directions &validDir, int &numDir);

   public:
   //Constructors and destructor
   Grid();
   Grid(int inRows, int inCols, int nAnts, int nDBugs);
   ~Grid();

   //Functions to run a simulation on the Grid
   void callMoves();
   void addTimeSteps();
   void callStarves();
   void callBreeds();
   void printGrid();

   //Necessary getters
   bool getOccupancy(int row, int column);
   int getNumRows();
   int getNumColumns();
};

#endif
