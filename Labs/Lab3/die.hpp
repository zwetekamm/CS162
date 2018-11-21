/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Header file for the Die class.
*******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <string>

using std::string;

class Die
{
	protected:
		int sides;
		string type;

	public:
		Die(int);
		virtual int roll();
		string getType();
		int getSides();
};

#endif
