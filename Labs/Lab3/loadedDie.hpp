/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Header file for the Loaded Die class.
*******************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <string>
#include "die.hpp"

using std::string;

class LoadedDie : public Die
{
	private:
		int sides;	
	public:
		LoadedDie(int &n);
		int roll();
};

#endif

