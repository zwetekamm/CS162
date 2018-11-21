/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Source file for the Loaded Die class, which is derived from 
 * the Die class. Loaded Die has a 25 percent chance to roll max value or zero.
*******************************************************************************/

#include "loadedDie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using std::rand;
using std::string;

/*********************************************************************
 * LoadedDie()
 * Constructor for LoadedDie, which has number of sides and is Loaded
 * Derived from class Die.
*********************************************************************/
LoadedDie::LoadedDie(int &n) : Die(n)
{
	sides = n;
	type = "Loaded";
}

/*********************************************************************
 * roll()
 * LoadedDie roll, which has 25% chance to roll max value or zero
*********************************************************************/
int LoadedDie::roll()
{
	//5
	if((rand() % 2 + 1) == 1)
	{
		if((rand() % 2 + 1) == 1)
		{
			return sides;			// 25% chance for max
		}
		else
		{
			return 0;				// 25% chance for 0
		}
	}
	else
	{
		return rand() % sides + 1;	// random integer roll
	}
}
