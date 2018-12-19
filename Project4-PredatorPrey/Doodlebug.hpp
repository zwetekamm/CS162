/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - Doodlebug.hpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the specification file for the class Doodlebug.
 *               A Doodlebug breeds every 8 time steps, has Type BUG, moves
 *               to a space containing an Ant or if no Ants are adjacent to
 *               it, moves to random unoccupied space on a Grid when move is
 *               called, and spawns a new Doodlebug onto an adjacent
 *               unoccupied space on a Grid when breed is called. It also
 *               can starve if it does not eat an Ant for three turns, so
 *               it has a variable to track if it starves and a private
 *               function to mark when it eats and reset the starve time.
 ************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int starveTime;
    void eatAnt();
    
public:
    Doodlebug(int, int); //Constuctor
    virtual Type getType(); //This identifies if it is an ANT or BUG
    virtual void move(Directions, int, bool);
    virtual bool starve();
    virtual Critter* breed(Directions[], int);
};

#endif
