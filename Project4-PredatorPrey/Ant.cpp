/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - Ant.cpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the class Ant. An Ant
 *               breeds every 3 time steps, has Type ANT, moves to a
 *               random unoccupied space on a Grid when move is called,
 *               and spawns a new Ant onto an adjacent unoccupied space on
 *               a Grid when breed is called.
 ************************************************************************/
#include "Ant.hpp"

/***************************************************
 *              Constructor for Ants
 ****************************************************/

Ant::Ant(int row, int col) : Critter(row, col, 3)
{}

/***************************************************
 *              getType() method
 * This will return the type of critter as an Ant
 ****************************************************/

Type Ant::getType()
{
    return ANT;
}

/***************************************************
 *              move() function
 * This takes an array of valid Directions and the
 * number of directions in the array. It moves the Ant
 * in a random direction and updates its row and
 * col variables appropriately. It also has a variable
 * to mark whether an Ant was found, but since an Ant
 * never eats another Ant, it does nothing with this
 * information.
 ****************************************************/
void Ant::move(Directions validDir, int numDirections, bool foundAnt)
{
    if (numDirections != 0)
    {
        //Moves it in the chosen random direction
        switch (validDir)
        {
            case UP:
                row--;				
                break;

            case RIGHT:
                col++;					
                break;

            case DOWN:
                row++;					
                break;

            case LEFT:
                col--;
                break;
        }

        //Marks that it moved so that it only moves once per time step
        moved = true;
    }
}

/***************************************************
 *              breed() function
 * This takes an array of valid Directions and the
 * number of directions in the array. If the Ant
 * has reached its breeding age, it will attempt to
 * spawn a new Ant next to it in a random direction.
 * This will be returned as a pointer to a new Ant
 * and MUST be assigned to a pointer when it is
 * called. Otherwise, memory leaks will happen.
 ****************************************************/
Critter* Ant::breed(Directions validDir[], int numDirections)
{
    Critter* critterPtr = nullptr;

    //Checks that the Ant is of breeding age
    if (breedReady)
    {
        //Gets a random direction and sets up initial variables
        int direction = rand() % numDirections;
        int currentDirection = validDir[direction];

        switch(currentDirection)
        {
            //Creates a new Ant in the cell above it
            case UP:    critterPtr = new Ant(row - 1, col);
                        break;

            //Creates a new Ant in the cell to the right of it
            case RIGHT: critterPtr = new Ant(row, col + 1);
                        break;

            //Creates a new Ant in the cell below it
            case DOWN:  critterPtr = new Ant(row + 1, col);
                        break;

            //Creates a new Ant in the cell to the left of it
            case LEFT:  critterPtr = new Ant(row, col - 1);
                        break;
        }

        //Sets its breedAge to 0 to begin tracking for the next time to breed
        resetBreedAge();
    }

    //This must be assigned to another pointer when called to avoid memory leaks
    return critterPtr;
}
