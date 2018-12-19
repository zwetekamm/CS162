/*************************************************************************
 * Program Name: Predator Prey Simulation (Group Project) - getValidData.hpp
 * Names:        Gabriel Cata, Drew Childs, William Conway,
 *               Michael Seehafer, Zachary Wetekamm
 * Date:         July 29, 2018
 * Description:  This is the specification file for the function getValidData().
 *               This function has a parameter of a user variable (does not have
 *               to be initialized) of type int or double. The function gets a
 *               string value from the user, checks if it is a valid integer or
 *               double, and prints error messages if the user does not enter
 *               the correct data type. The function continues in a loop until
 *               the user provides a valid entry. It then converts the string to
 *               an integer or double and stores this value in the variable
 *               passed by reference. It also checks against minimum and maximum
 *               values. The function is overloaded so that the user may pass
 *               an integer or double by reference to get the correct data type.
 *
 *               (This is Michael's utility function.)
 *******************************************************************************/
#ifndef GET_VALID_DATA_HPP
#define GET_VALID_DATA_HPP

void getValidData(int &userInt, int min, int max);
void getValidData(double &userDouble, double min, double max);

#endif
