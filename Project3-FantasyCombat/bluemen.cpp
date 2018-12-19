/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Blue Men.
***********************************************************/
#include "bluemen.hpp"

/***********************************************************
* BlueMen()
* Description: Default constructor; Blue Men have 3 armor
* and 12 strength points.
***********************************************************/
BlueMen::BlueMen()
{
	this->armor = 3;
	this->strength = 12;
	this->type = "Blue Men";
}

/***********************************************************
* attack()
* Description: Rolls 2, 10-sided die for random attack.
***********************************************************/
int BlueMen::attack()
{
	int attack1 = rand() % 10 + 1;
	int attack2 = rand() % 10 + 1;
	return attack1 + attack2;
}

/***********************************************************
* defend()
* Description: Rolls 3, 2-sided die for random defense. If
* Blue Men have 8 or less strength, roll 2 die; else if
* strength is 4 or less, roll 1 die.
***********************************************************/
int BlueMen::defend()
{
	int defend1 = rand() % 6 + 1;
	int defend2 = rand() % 6 + 1;
	int defend3 = rand() % 6 + 1;

	if (strength > 8)
	{
		return defend1 + defend2 + defend3;
	}
	else if (strength > 4)
	{
		return defend1 + defend2;
	}
	else
	{
		return defend1;
	}
}

/***********************************************************
* getArmor()
* Description: Returns the armor value. 
***********************************************************/
int BlueMen::getArmor()
{
	return this->armor;
}

/***********************************************************
* getStrength()
* Description: Returns the strength points.
***********************************************************/
int BlueMen::getStrength()
{
	return this->strength;
}

/***********************************************************
* getType()
* Description: Returns the string type.
***********************************************************/
std::string BlueMen::getType()
{
	return this->type;
}

/***********************************************************
* calcDamage()
* Description: Calcualtes the damage done to this defender.
***********************************************************/
void BlueMen::calcDamage(int damage)
{	
	// if the character dies
	if (this->strength - damage < 0)
	{
		this->strength = 0;
	}
	else
	{
		this->strength -= damage;
	}
}

/***********************************************************
* isDead()
* Description: Returns true if strength < 0.
***********************************************************/
bool BlueMen::isDead()
{
	if (this->strength < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}