/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the class Harry Potter.
***********************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter : public Character
{
	private:
		int armor;
		int strength;
		std::string type;
		bool hasHogwarts;

	public:
		HarryPotter();
		virtual int attack();
		virtual int defend();
		virtual int getArmor();
		virtual int getStrength();
		virtual std::string getType();
		virtual void calcDamage(int);
		virtual bool isDead();
};

#endif