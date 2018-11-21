/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Penguin.
*******************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"
#include <string>

class Penguin : public Animal {
	public:
		Penguin();
		Penguin(int);
};

#endif
