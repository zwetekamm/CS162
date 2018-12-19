/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - Doodlebug.cpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the class Doodlebug.
 *               A Doodlebug breeds every 8 time steps, has Type BUG, moves
 *               to a space containing an Ant or if no Ants are adjacent to
 *               it, moves to random unoccupied space on a Grid when move is
 *               called, and spawns a new Doodlebug onto an adjacent
 *               unoccupied space on a Grid when breed is called. It also
 *               can starve if it does not eat an Ant for three turns, so
 *               it has a variable to track if it starves and a private
 *               function to mark when it eats and reset the starve time.
 ************************************************************************/
#include "Doodlebug.hpp"

/***************************************************
 *           Constructor for Doodlebug
 ****************************************************/

Doodlebug::Doodlebug(int row, int col) : Critter(row, col, 8)
{
    starveTime = 0;
}

/***************************************************
 *              getType() function
 * This will return BUG for the type for Doodlebug.
 ****************************************************/

Type Doodlebug::getType()
{
    return BUG;
}

/***************************************************
 *              eatAnt() function
 * This resets the Doodlebug's starve time to
 * indicate that it has eaten this turn.
 ****************************************************/

void Doodlebug::eatAnt()
{
    starveTime = 0;
}

/***************************************************
 *              starve() function
 * This checks to see if a Doodlebug has not eaten
 * in 3 turns. It returns a boolean value for whether
 * or not the Doodlebug has starved.
 ****************************************************/

bool Doodlebug::starve()
{
    if (starveTime >= 3)
    {
        return true;
    }

    else
    {
        return false;
    }
}

/***************************************************
 *              move() function
 * This takes an array of valid Directions and the
 * number of directions in the array. It moves the
 * Doodlebug in a random direction and updates its row
 * and col variables appropriately. If an Ant was
 * found, it eats the Ant and resets its starveTime.
 * If no Ant was found, its starveTime increases by 1.
 ****************************************************/
void Doodlebug::move(Directions validDir, int numDirections, bool foundAnt)
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

        //The Doodlebug eats an Ant and resets its starve time
        if (foundAnt)
        {
            eatAnt();
        }

        //The Doodlebug does not eat and gets one step closer to starving
        else
        {
            starveTime++;
        }
    
        //Marks that it moved so that it only moves once per time step
        moved = true;
    }

    //The Doodlebug does not move and gets one step closer to starving
    else
    {
        starveTime++;
    }
}

/***************************************************
 *              breed() function
 * This takes an array of valid Directions and the
 * number of directions in the array. If the
 * Doodlebug has reached its breeding age, it will
 * attempt to spawn a new Doodlebug next to it in a
 * random direction. This will be returned as a pointer
 * to a new Doodlebug and MUST be assigned to a pointer
 * when it is called. Otherwise, memory leaks will
 * occur.
 ****************************************************/
Critter* Doodlebug::breed(Directions validDir[], int numDirections)
{
    Critter* critterPtr = nullptr;

    //Checks that the Doodlebug is of breeding age
    if (breedReady)
    {
        //Gets a random direction and sets up initial variables
        int direction = rand() % numDirections;
        int currentDirection = validDir[direction];

        switch(currentDirection)
        {
            //Creates a new Doodlebug in the cell above it
            case UP:    critterPtr = new Doodlebug(row - 1, col);
                        break;

            //Creates a new Doodlebug in the cell above it
            case RIGHT: critterPtr = new Doodlebug(row, col + 1);
                        break;

            //Creates a new Doodlebug in the cell above it
            case DOWN:  critterPtr = new Doodlebug(row + 1, col);
                        break;

            //Creates a new Doodlebug in the cell above it
            case LEFT:  critterPtr = new Doodlebug(row, col - 1);
                        break;
        }

        //Sets its breedAge to 0 to begin tracking for the next time to breed
        resetBreedAge();
    }

    //This must be assigned to another pointer when called to avoid memory leaks
    return critterPtr;
}
