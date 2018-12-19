/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the class Critter.
 *               This is an abstract base class, containing a row and
 *               column to track its location, age variables to track how
 *               long it has been since breeding and when it actually
 *               engages in breeding, a boolean variable to indicate when
 *               it is ready to breed, and a boolean variable to indicate
 *               when it has moved. It has virtual functions for
 *               starving, getting its Critter Type, moving, and breeding. 
 ************************************************************************/
#include "Critter.hpp"

/***************************************************
 *              Constructor for Critter
 ****************************************************/
Critter::Critter(int row, int col, int breedReadyAge)
{
    this->breedReadyAge = breedReadyAge;
    this->row = row;
    this->col = col;
    this->moved = false;
    this->breedReady = false;
    this->breedAge = 0;
}

/***************************************************
 *              getRow() function
 * This returns the row that a critter is on
 ****************************************************/

int Critter::getRow()
{
    return row;
}

/***************************************************
 *              getCol() function
 * This returns the column that a critter is on
 ****************************************************/

int Critter::getCol()
{
    return col;

}

/***************************************************
 *              getMoved() function
 * This returns the bool if the critter has moved
 ****************************************************/

bool Critter::getMoved()
{
    return moved;
}

/***************************************************
 *              resetMove() function
 * This resets the boolean variable to indicate
 * that a Critter has not yet moved.
 ****************************************************/

void Critter::resetMove()
{
    moved = false;
}

/***************************************************
 *              incrementBreedAge()
 * This increments the amount of time since a  
 * critter has bred and updates the boolean
 * breedReady variable if necessary.
 ****************************************************/

void Critter::incrementBreedAge()
{
    breedAge++;

    if (breedAge == breedReadyAge)
    {
        breedReady = true;
    }
}

/***************************************************
 *           resetBreedAge() function
 * This resets the breeding age back to 0 and sets
 * breedReady to false if it already wasn't.
 ****************************************************/

void Critter::resetBreedAge()
{
    breedAge = 0;
    breedReady = false;
}

/***************************************************
 *              starve() function
 * This function checks if a Critter has starved
 * to death. It returns a boolean value for whether
 * or not the Critter starved.
 ****************************************************/

bool Critter::starve()
{
    return false; //By default, Critters never starve
}
