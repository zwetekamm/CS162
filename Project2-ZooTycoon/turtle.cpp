/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Turtle.
*******************************************************************************/
#include "turtle.hpp"

/*******************************************************************************
 * Turtle() : Animal()
 * Description: Default constructor for Turtle, which inherits Animal class.
*******************************************************************************/
Turtle::Turtle() : Animal() {
	cost = 100;
	babies = 10;
	foodCost = 5;
	payoff = cost * .05;		// 5 percent payoff
	type = "Turtle";
}

/*******************************************************************************
 * Turtle() : Animal()
 * Description: Default constructor for Turtle, which inherits Animal class.
*******************************************************************************/
Turtle::Turtle(int a) : Animal() {
	age = a;
	cost = 100;
	babies = 10;
	foodCost = 5;
	payoff = cost * .05;
	type = "Turtle";
}
