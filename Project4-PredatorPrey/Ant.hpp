/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the specification file for the class Ant. An Ant
 *               breeds every 3 time steps, has Type ANT, moves to a
 *               random unoccupied space on a Grid when move is called,
 *               and spawns a new Ant onto an adjacent unoccupied space on
 *               a Grid when breed is called.
 ************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
public:
    Ant(int, int); //Constructor
    virtual Type getType(); //This identifies if it is an ANT or BUG
    virtual void move(Directions, int, bool);
    virtual Critter* breed(Directions[], int);
};

#endif
