/***********************************************************
* Author: Zachary Wetekamm
* Date: 08/05/18
* Description: Source file for the class Harry Potter.
***********************************************************/
#include "harrypotter.hpp"

/***********************************************************
* HarryPotter()
* Description: Default constructor; Harry Potter has 0 armor
* and 10 strength points. If strength points reach 0, he
* recovers only once with 20 strength points.
***********************************************************/
HarryPotter::HarryPotter()
{
	this->armor = 0;
	this->strength = 10;
	this->type = "Harry Potter";
	this->hasHogwarts = true;
}

/***********************************************************
* attack()
* Description: Rolls 2, 6-sided die for random attack.
***********************************************************/
int HarryPotter::attack()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	return attack1 + attack2;
}

/***********************************************************
* defend()
* Description: Rolls 2, 6-sided die for random defense.
***********************************************************/
int HarryPotter::defend()
{
	int defend1 = rand() % 6 + 1;
	int defend2 = rand() % 6 + 1;

	return defend1 + defend2;
}

/***********************************************************
* getArmor()
* Description: Returns the armor value. 
***********************************************************/
int HarryPotter::getArmor()
{
	return this->armor;
}

/***********************************************************
* getStrength()
* Description: Returns the strength points.
***********************************************************/
int HarryPotter::getStrength()
{
	return this->strength;
}

/***********************************************************
* getType()
* Description: Returns the string type.
***********************************************************/
std::string HarryPotter::getType()
{
	return this->type;
}

/***********************************************************
* calcDamage()
* Description: Calcualtes the damage done to this defender.
* If Harry Potter dies, Hogwarts is used to return him to
* life--strength is set to 20.
***********************************************************/
void HarryPotter::calcDamage(int damage)
{	
	// if the character dies
	if (this->strength - damage < 0 && hasHogwarts)
	{
		this->strength = 20;
		hasHogwarts = false;
	}
	else
	{
		this->strength -= damage;
	}
}

/***********************************************************
* isDead()
* Description: Returns true if strength < 0 and Harry has
* already used Howgarts to return to life.
***********************************************************/
bool HarryPotter::isDead()
{
	if (this->strength < 1 && !hasHogwarts)
	{
		return true;
	}
	else if (this->strength < 1 && hasHogwarts)
	{
		std::cout << "Hogwarts revives Harry Potter!" << std::endl;
		return false;
	}
	else
	{
		return false;
	}
}
