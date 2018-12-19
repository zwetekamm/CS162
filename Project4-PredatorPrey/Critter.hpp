/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - Critter.hpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the specification file for the class Critter.
 *               This is an abstract base class, containing a row and
 *               column to track its location, age variables to track how
 *               long it has been since breeding and when it actually
 *               engages in breeding, a boolean variable to indicate when
 *               it is ready to breed, and a boolean variable to indicate
 *               when it has moved. It has virtual functions for
 *               starving, getting its Critter Type, moving, and breeding. 
 ************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <stdlib.h>
#include <iostream>

enum Directions {UP, RIGHT, DOWN, LEFT};
enum Type {ANT, BUG};

class Critter
{
protected:
    
    int row;
    int col;
    int breedAge;
    int breedReadyAge;
    bool breedReady;
    bool moved;
    
public:
    // Constructor
    Critter(int row, int col, int breedingAge);
    
    // Virtual base class functions   
    virtual bool starve();
    virtual Type getType() = 0;
    virtual void move(Directions, int, bool) = 0;
    virtual Critter* breed(Directions[], int) = 0;
    
    // Getters
    int getRow();
    int getCol();
    bool getMoved();
    
    // Setters
    void resetMove();
    void incrementBreedAge();
    void resetBreedAge();
    
};

#endif
