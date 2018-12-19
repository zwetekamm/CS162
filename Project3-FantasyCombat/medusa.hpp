/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the class Medusa.
***********************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character
{
	private:
		int armor;
		int strength;
		std::string type;

	public:
		Medusa();
		virtual int attack();
		virtual int defend();
		virtual int getArmor();
		virtual int getStrength();
		virtual std::string getType();
		virtual void calcDamage(int);
		virtual bool isDead();
};

#endif