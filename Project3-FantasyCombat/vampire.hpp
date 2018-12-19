/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the class Vampire.
***********************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character
{
	private:
		int armor;
		int strength;
		std::string type;

	public:
		Vampire();
		virtual int attack();
		virtual int defend();
		virtual int getArmor();
		virtual int getStrength();
		virtual std::string getType();
		virtual void calcDamage(int);
		virtual bool isDead();
};

#endif