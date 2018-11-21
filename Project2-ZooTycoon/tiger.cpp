/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Tiger.
*******************************************************************************/
#include "tiger.hpp"

/*******************************************************************************
 * Tiger() : Animal()
 * Description: Default constructor for Tiger, which inherits the Animal class.
*******************************************************************************/
Tiger::Tiger() : Animal() {
	cost = 10000;
	babies = 1;
	foodCost = 50;
	payoff = cost * .2;     // 20 percent payoff
	type = "Tiger";
}

/*******************************************************************************
 * Tiger(int) : Animal()
 * Description:
*******************************************************************************/
Tiger::Tiger(int a) : Animal() {
	age = a;
	cost = 10000;
	babies = 1;
	foodCost = 50;
	payoff = cost * .2;
	type = "Tiger";
}
