/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Source file for Die class for the dice game of War. All die
 * has a number of sides and defaults to "Unloaded" type.
*******************************************************************************/

#include "die.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::rand;

/*********************************************************************
 * Die()
 * Constructor for Die, which has number of sides and is Unloaded
*********************************************************************/
Die::Die(int n)
{
	sides = n;
	type = "Unloaded";
}

/*********************************************************************
 * roll()
 * Random integer generated based on number of sides
*********************************************************************/
int Die::roll()
{
	return rand() % sides + 1;
}

//return type
string Die::getType()
{
	return type;
}

//return sides
int Die::getSides()
{
	return sides;
}
