/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the base class Animal.
*******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "animal.hpp"
#include <iostream>
#include <string>

using std::string;

class Animal {
	protected:
		int age;
		int cost;
		int babies;
		int foodCost;
		int payoff;
		string type;

	public:
		Animal();
		~Animal();
		Animal(int);
		int getAge();
		int getCost();
		int getBabies();
		int getFoodCost();
		int getPayoff();
		string getType();
		void increaseAge();
};

#endif
