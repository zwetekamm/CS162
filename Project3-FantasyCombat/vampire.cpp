/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Vampire
***********************************************************/
#include "vampire.hpp"

/***********************************************************
* Vampire()
* Description: Default constructor; Blue Men have 3 armor
* and 12 strength points.
***********************************************************/
Vampire::Vampire()
{
	this->armor = 1;
	this->strength = 18;
	this->type = "Vampire";
}

/***********************************************************
* attack()
* Description: Rolls 1, 12-sided die for random attack.
***********************************************************/
int Vampire::attack()
{
	int attack1 = rand() % 12 + 1;
	return attack1;
}

/***********************************************************
* defend()
* Description: Rolls 1, 6-sided die for random defense.
***********************************************************/
int Vampire::defend()
{
	int charm = rand() % 2;
	int defend1 = rand() % 6 + 1;

	// 50% chance to charm opponent
	if (charm == 1)
	{
		// arbitrary integer flag for charm
		return 99;
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
int Vampire::getArmor()
{
	return this->armor;
}

/***********************************************************
* getStrength()
* Description: Returns the strength points.
***********************************************************/
int Vampire::getStrength()
{
	return this->strength;
}

/***********************************************************
* getType()
* Description: Returns the string type.
***********************************************************/
std::string Vampire::getType()
{
	return this->type;
}

/***********************************************************
* calcDamage()
* Description: Calcualtes the damage done to this defender.
***********************************************************/
void Vampire::calcDamage(int damage)
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
bool Vampire::isDead()
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