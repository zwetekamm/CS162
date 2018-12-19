/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the class Grid. It
 *               represents a 2D grid of Ants, Doodlebugs, and blank spaces.
 *               It has functions to call these critters to move, breed,
 *               and starve. It also has functions to add a time step and
 *               print out the current state of the Grid.
 ************************************************************************/
#include "Grid.hpp"

using std::cout;
using std::endl;

/***************************************************
 *             Default Constructor 
 * Creates a 20x20 Grid with 5 Doodlebugs and 100 Ants
 ****************************************************/
Grid::Grid()
{
   //Initializes row and column variables to 20 if not given other input
   numRows = 20;
   numColumns = 20;

   //Dynamically allocates 2d array with numRows and numColumns
   critterArr = new Critter**[numRows];

   for (int r = 0; r < numRows; r++)
   {
       critterArr[r] = new Critter* [numColumns];
   }

   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         critterArr[r][c] = nullptr;
      }
   }

   
   //Creates and randomly places Doodlebugs
   for (int i = 0; i < 5; i++)
   {
      bool hasBeenPlaced = false;

      while (!hasBeenPlaced)
      {
         int r = rand() % numRows;
         int c = rand() % numColumns;

         if (!critterArr[r][c])
         {
            critterArr[r][c] = new Doodlebug(r, c);
            hasBeenPlaced = true;
         }
      }
   }

   //Creates and randomly places Ants
   for (int i = 0; i < 100; i++)
   {
      bool hasBeenPlaced = false;

      while (!hasBeenPlaced)
      {
         int r = rand() % numRows;
         int c = rand() % numColumns;
      
         if (!critterArr[r][c])
         {
            critterArr[r][c] = new Ant(r, c);
            hasBeenPlaced = true;
         }
      }
   }
}

/***************************************************
 *                   Constructor 
 * Constructor that takes a number of rows and
 * columns for the board and an initial number of
 * Doodlebugs and Ants.
 ****************************************************/
Grid::Grid(int inRows, int inColumns, int inDbugs, int inAnts)
{
   //Initializes row and column variables using input
   numRows = inRows;
   numColumns = inColumns;

   /*If there are more critters than Grid squares, uses the 
   default values and print a warning. Otherwise uses the
   input numbers.*/
   if (inDbugs + inAnts > inRows * inColumns)
   {
      cout << "There are more bugs than squares!" 
           << " Resetting to defaults." << endl;

      inDbugs = 5;
      inAnts = 100;
      numRows = 20;
      numColumns = 20;
   }

   //Dynamically allocates 2d array with numRows and numColumns
   critterArr = new Critter**[numRows];

   for (int r = 0; r < numRows; r++)
   {
       critterArr[r] = new Critter* [numColumns];
   }

   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         critterArr[r][c] = nullptr;
      }
   }

   
   //Creates and randomly places Doodlebugs
   for (int i = 0; i < inDbugs; i++)
   {
      bool hasBeenPlaced = false;

      while (!hasBeenPlaced)
      {
         int r = rand() % numRows;
         int c = rand() % numColumns;
      
         if (!critterArr[r][c])
         {
            critterArr[r][c] = new Doodlebug(r, c);
            hasBeenPlaced = true;
         }
      }
   }

   //Creates and randomly places Ants
   for (int i = 0; i < inAnts; i++)
   {
      bool hasBeenPlaced = false;

      while (!hasBeenPlaced)
      {
         int r = rand() % numRows;
         int c = rand() % numColumns;
      
         if (!critterArr[r][c])
         {
            critterArr[r][c] = new Ant(r, c);
            hasBeenPlaced = true;
         }
      }
   }
}

/***************************************************
 *                  Destructor
 * This frees dynamically allocated memory from
 * the array. 
 ****************************************************/
Grid::~Grid()
{
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         if (critterArr[r][c] != nullptr)
         delete critterArr[r][c];
      }
   }   
   for (int r = 0; r < numRows; r++)
   {
      delete [] critterArr[r];
   } 
   delete [] critterArr;
   critterArr = nullptr;
}

/***************************************************
 *                callStarves() function
 * This function adds a time step to the Critters,
 * incrementing their breed ages.
 ****************************************************/
void Grid::addTimeSteps()
{
   //Calls any valid Critter's method to increment their breed age
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         if ((critterArr[r][c]) != nullptr)
         {
            critterArr[r][c]->incrementBreedAge();
         }
      }
   } 
}

/***************************************************
 *                callStarves() function
 * This function calls the starve() function on all
 * Critters, and if a Doodlebug has starved, this
 * function removes it from the array.
 ****************************************************/
void Grid::callStarves()
{
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         if (critterArr[r][c] != nullptr)
         {
            if (critterArr[r][c]->starve())
            {
               delete critterArr[r][c];
               critterArr[r][c] = nullptr;
            }
         }
      }
   }
}

/***************************************************
 *           getBreedDirections() function
 * Checks the array bounds and occupancy around the
 * Critter at the row and column indicated by the
 * passed parameters. Updates an array of Directions
 * and the number of valid directions, both passed
 * by reference.
 ****************************************************/
bool Grid::getBreedDirections(int row, int col, Directions* validDir, int &numDir)
{
   //Checks if cell above critter is a valid breeding location
   if (row - 1 >= 0)
   {
      if (!getOccupancy(row - 1, col))
      {
         validDir[numDir] = UP;
         numDir++;
      }
   }

   //Checks if cell to the right of critter is a valid breeding location
   if (col + 1 < numColumns)
   {
      if (!getOccupancy(row, col + 1))
      {
         validDir[numDir] = RIGHT;
         numDir++;
      }
   }

   //Checks if cell below critter is a valid breeding location
   if (row + 1 < numRows)
   {
      if (!getOccupancy(row + 1, col))
      {
         validDir[numDir] = DOWN;
         numDir++;
      }
   }

   //Checks if cell to the left of critter is a valid breeding location
   if (col - 1 >= 0)
   {
      if (!getOccupancy(row, col - 1))
      {
         validDir[numDir] = LEFT;
         numDir++;
      }
   }
}

/***************************************************
 *           getMoveDirections() function
 * Checks the array bounds and occupancy around the
 * Critter at the row and column indicated by the
 * passed parameters. Updates an array of Directions
 * and the number of valid directions, both passed
 * by reference.
 ****************************************************/
void Grid::getMoveDirection(int row, int col, Directions &dir, int &numDir)
{
   int direction = rand() % 3;

   switch (direction)
   {
      //Checks if cell above critter is a valid breeding location
      case UP:
         if (row - 1 >= 0)
         {
            if (!getOccupancy(row - 1, col))
            {
               dir = UP;
               numDir++;
            }
         }
         break;

      //Checks if cell to the right of critter is a valid breeding location
      case RIGHT:
         if (col + 1 < numColumns)
         {
            if (!getOccupancy(row, col + 1))
            {
               dir = RIGHT;
               numDir++;
            }
         }
         break;

      //Checks if cell below critter is a valid breeding location
      case DOWN:
         if (row + 1 < numRows)
         {
            if (!getOccupancy(row + 1, col))
            {
               dir = DOWN;
               numDir++;
            }
         }
         break;

      //Checks if cell to the left of critter is a valid breeding location
      case LEFT:
         if (col - 1 >= 0)
         {
            if (!getOccupancy(row, col - 1))
            {
               dir = LEFT;
               numDir++;
            }
         }
         break;
   }
}

/**********************************************************
 *                       getValidAnts()
 * This function checks if an adjacent cell contains an ant
 * critter. If any ants are found, numAnt is incremented
 * and sets the boolean foundAnt true.
**********************************************************/
bool Grid::getValidAnts(int row, int col, Directions &validAnt, int &numAnt)
{
   bool foundAnt;

   //Checks if cell above it contains an ant
   if (row - 1 >= 0 && !foundAnt)
   {
      if (critterArr[row - 1][col] != nullptr)
      {
         if (critterArr[row - 1][col]->getType() == ANT)
         {
            validAnt = UP;
            numAnt++;
            foundAnt = true;
         }
      }
   }

   //Checks if cell to the right it contains an ant
   if (col + 1 < numColumns && !foundAnt)
   {
      if (critterArr[row][col + 1] != nullptr)
      {
         if (critterArr[row][col+1]->getType() == ANT)
         {
            validAnt = RIGHT;
            numAnt++;
            foundAnt = true;
         }
      }
   }

   //Checks if cell below it contains an ant
   if (row + 1 < numRows && !foundAnt)
   {
      if (critterArr[row + 1][col] != nullptr)
         {
         if (critterArr[row+1][col]->getType() == ANT)
         {
            validAnt = DOWN;
            numAnt++;
            foundAnt = true;
         }
      }
   }

   //Checks if cell to the left it contains an ant 
   if (col - 1 >= 0 && !foundAnt)
   {
      if (critterArr[row][col - 1] != nullptr)
      {
         if (critterArr[row][col-1]->getType() == ANT)
         {
            validAnt = LEFT;
            numAnt++;
            foundAnt = true;
         }
      }
   }

   //If any ants are found, return true
   return foundAnt;
}

/**********************************************************
 *                       callMoves()
 * This function has all the Doodlebugs move. If they can,
 * they will move and eat an Ant, so the array will be
 * updated with a new location for the Doodlebug and will
 * delete the Ant. Otherwise, the Doodlebugs simply move
 * to an adjacent space. Ants will then also move to an
 * adjacent space if able. Doodlebugs will also update
 * their starve time if they do not eat. All Critters will
 * only move one time if they are able.
**********************************************************/
void Grid::callMoves()
{
   //Reset moves for all Ants and Doodlebugs
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numRows; c++)
      {
         if (critterArr[r][c] != nullptr)
         {
            critterArr[r][c]->resetMove();
         }
      }
   }

   //Call Doodlebug moves
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         int numDir = 0;
         Directions dir;
         if (critterArr[r][c] != nullptr)
         {
            //Only moves Doodlebugs that have not already moved this turn
            if (critterArr[r][c]->getType() == BUG
                && critterArr[r][c]->getMoved() == false)
            {
               //Checks for surrounding Ants
               bool foundAnts = getValidAnts(r, c, dir, numDir);
               if (foundAnts)
               {
                  //Doodlebug moves and eats an Ant, and
                  //the array is updated accordingly
                  critterArr[r][c]->move(dir, numDir, foundAnts);
                  int newRow = critterArr[r][c]->getRow();
                  int newCol = critterArr[r][c]->getCol();
                  delete critterArr[newRow][newCol];
                  critterArr[newRow][newCol] = critterArr[r][c];
                  critterArr[r][c] = nullptr;
               }
         
               else
               {
                  //Moves Doodlebug in a random direction to an unoccupied cell
                  getMoveDirection(r, c, dir, numDir);
                  critterArr[r][c]->move(dir, numDir, false);
                  if (numDir != 0)
                  {
                     //Updates the array of pointers if it actually could move
                     int newRow = critterArr[r][c]->getRow();
                     int newCol = critterArr[r][c]->getCol();
                     critterArr[newRow][newCol] = critterArr[r][c];
                     critterArr[r][c] = nullptr;
                  }
               }
            }
         } 
      }
   } 

   //Calls moves for the Ants
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         int numDir = 0;
         Directions validDir;

         if (critterArr[r][c] != nullptr)
         {
            //Ensures that it only moves Ants that haven't moved yet this turn
            if (critterArr[r][c]->getType() == ANT
                && critterArr[r][c]->getMoved() == false)
            {
               //Moves the Ant in a random direction to an unoccupied cell (if able)
               getMoveDirection(r, c, validDir, numDir);
               critterArr[r][c]->move(validDir, numDir, false);
               if (numDir != 0)
               {
                  //Updates the array of pointers if it actually could move
                  int newRow = critterArr[r][c]->getRow();
                  int newCol = critterArr[r][c]->getCol();
                  critterArr[newRow][newCol] = critterArr[r][c];
                  critterArr[r][c] = nullptr;
               }
            }
         }
      } 
   }  
}

/***************************************************
 *              callBreeds() function
 * Checks the array bounds and occupancy around each
 * Critter and then calls the breed() function for
 * each Critter if there is a possible location where
 * they can spawn a new Critter. It updates the
 * array to hold the Critters that spawned from this.
 ****************************************************/
void Grid::callBreeds()
{
   //Steps through the entire array
   for (int r = 0; r < numRows; r++)
   {
      for (int c = 0; c < numColumns; c++)
      {
         int numDir = 0;
         Directions validDir[4];
         Critter* critterPtr = nullptr;

         getBreedDirections(r, c, validDir, numDir);

         //Calls the breed function if there is a critter and valid location 
         if (critterArr[r][c] != nullptr && numDir != 0)
         {
            critterPtr = critterArr[r][c]->breed(validDir, numDir);
         }

         //Adds the new critter to the array
         if (critterPtr != nullptr)
         {
            int newRow = critterPtr->getRow();
            int newCol = critterPtr->getCol();
            critterArr[newRow][newCol] = critterPtr;
            critterPtr = nullptr;
         }
      }
   } 
}

/***************************************************
 *              printGrid() function
 * This function prints out the current locations
 * of all the Ants and Doodlebugs, representing Ants
 * with a 'O' and Doodlebugs with an 'X'.
 ****************************************************/
void Grid::printGrid()
{
   //Prints a top boarder
   for (int r = 0; r < numColumns + 2; r++)
   {
      cout << '-';
   }

   //Prints the left boarder, a row, and the right boarder
   for (int r = 0; r < numRows; r++)
   {
      cout << endl << '|';
      for (int c = 0; c < numColumns; c++)
      {
         if (critterArr[r][c] != nullptr)
         {
            if (critterArr[r][c]->getType()==BUG)
            {
               cout << 'X';
            }
            else if (critterArr[r][c]->getType()==ANT)
            {
               cout << 'O';
            }
         }
         else
         {
            cout << ' ';
         }
      }
      cout << '|';
   }
   
   //Prints a bottom boarder
   cout << endl;
   for (int r = 0; r < numColumns + 2; r++)
   {
      cout <<  '-';
   }

   cout << endl;
}

/***************************************************
 *              printGrid() function
 * This function checks whether or not a square is
 * occurpied by a Critter. It takes a row and column
 * as parameters, returns true if there is a Critter
 * there, and returns false if there is not. 
 ****************************************************/
bool Grid::getOccupancy(int row, int column)
{
   //Returns true if there is a valid Critter at index, else returns false
   if (critterArr[row][column] != nullptr)
   {
      return true;
   }

   else
   {
      return false;
   }
}
