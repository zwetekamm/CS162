/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Turtle.
*******************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"
#include <string>

class Turtle : public Animal {
	public:
		Turtle();
		Turtle(int);
};

#endif
