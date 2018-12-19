/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Barbarian.
***********************************************************/
#include "barbarian.hpp"

/***********************************************************
* Barbarian()
* Description: Default constructor.
***********************************************************/
Barbarian::Barbarian()
{
	this->armor = 0;
	this->strength = 12;
	this->type = "Barbarian";
}

/***********************************************************
* attack()
* Description: Rolls 2, 6-sided die for random attack.
***********************************************************/
int Barbarian::attack()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	return attack1 + attack2;
}

/***********************************************************
* defend()
* Description: Rolls 2, 2-sided die for random defense. 
***********************************************************/
int Barbarian::defend()
{
	int defend1 = rand() % 6 + 1;
	int defend2 = rand() % 6 + 1;
	return defend1 + defend2;
}

/***********************************************************
* getArmor()
* Description: Returns the armor value. 
***********************************************************/
int Barbarian::getArmor()
{
	return this->armor;
}

/***********************************************************
* getStrength()
* Description: Returns the strength points.
***********************************************************/
int Barbarian::getStrength()
{
	return this->strength;
}

/***********************************************************
* getType()
* Description: Returns the string type.
***********************************************************/
std::string Barbarian::getType()
{
	return this->type;
}

/***********************************************************
* calcDamage()
* Description: Calcualtes the damage done to this defender.
***********************************************************/
void Barbarian::calcDamage(int damage)
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
bool Barbarian::isDead()
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