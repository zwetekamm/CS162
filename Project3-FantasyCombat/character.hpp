/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Header file for the base class Character.
***********************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Character
{
	protected:
		int armor;
		int strength;
		std::string type;

	public:
		Character();
		virtual ~Character();
		virtual int attack() = 0;
		virtual int defend() = 0;
		virtual int getArmor() = 0;
		virtual int getStrength() = 0;
		virtual std::string getType() = 0;
		virtual void calcDamage(int) = 0;
		virtual bool isDead() = 0;
};

#endif