/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the class Barbarian.
***********************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
	private:
		int armor;
		int strength;
		std::string type;

	public:
		Barbarian();
		virtual int attack();
		virtual int defend();
		virtual int getArmor();
		virtual int getStrength();
		virtual std::string getType();
		virtual void calcDamage(int);
		virtual bool isDead();
};

#endif