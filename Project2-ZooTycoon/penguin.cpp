/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Penguin.
*******************************************************************************/
#include "penguin.hpp"

/*******************************************************************************
 * Penguin() : Animal()
 * Description: Default constructor for Penguin, which inherits Animal class.
*******************************************************************************/
Penguin::Penguin() : Animal() {
	cost = 1000;
	babies = 5;
	foodCost = 10;
	payoff = cost * .1;     // 10 percent payoff
	type = "Penguin";
}

/*******************************************************************************
 * Penguin(int) : Animal()
 * Description: Constructor to set age.
*******************************************************************************/
Penguin::Penguin(int a) : Animal() {
	age = a;
	cost = 1000;
	babies = 5;
	foodCost = 10;
	payoff = cost * .1;
	type = "Penguin";
}
