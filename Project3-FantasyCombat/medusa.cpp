/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Medusa.
***********************************************************/
#include "medusa.hpp"

/***********************************************************
* Medusa()
* Description: Default constructor; Medusa has 3 armor and
* 8 strength points.
***********************************************************/
Medusa::Medusa()
{
	this->armor = 3;
	this->strength = 8;
	this->type = "Medusa";
}

/***********************************************************
* attack()
* Description: Rolls 2, 6-sided die for random attack. 
* If Medusa rolls a 12, she will turn her opponent to stone
* and instantly wins combat.
***********************************************************/
int Medusa::attack()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	
	if (attack1 + attack2 == 12)
	{
		// arbitrary integer flag for stone gaze
		return 100;
	}
	else
	{
		return attack1 + attack2;
	}
}

/***********************************************************
* defend()
* Description: Rolls 1, 6-sided die for random defense.
***********************************************************/
int Medusa::defend()
{
	int defend1 = rand() % 6 + 1;

	return defend1;

}

/***********************************************************
* getArmor()
* Description: Returns the armor value. 
***********************************************************/
int Medusa::getArmor()
{
	return this->armor;
}

/***********************************************************
* getStrength()
* Description: Returns the strength points.
***********************************************************/
int Medusa::getStrength()
{
	return this->strength;
}

/***********************************************************
* getType()
* Description: Returns the string type.
***********************************************************/
std::string Medusa::getType()
{
	return this->type;
}

/***********************************************************
* calcDamage()
* Description: Calcualtes the damage done to this defender.
***********************************************************/
void Medusa::calcDamage(int damage)
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
bool Medusa::isDead()
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