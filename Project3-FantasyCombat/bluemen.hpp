/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the class Blue Men.
***********************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class BlueMen : public Character
{
	private:
		int armor;
		int strength;
		std::string type;

	public:
		BlueMen();
		virtual int attack();
		virtual int defend();
		virtual int getArmor();
		virtual int getStrength();
		virtual std::string getType();
		virtual void calcDamage(int);
		virtual bool isDead();
};

#endif