/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the specification file for the function readMenu().
 *               This function has parameters of an array of string items
 *               representing the various items on a menu and an integer
 *               representing the number of items on the menu. This program
 *               prints the menu, gets a choice from the user, and performs input
 *               validation to ensure that the choice is an integer that exists
 *               on the menu list. It continues until the user has provided a
 *               valid choice and then returns the choice as an integer.
 *
 *               (This is Michael's utility function.)
 *******************************************************************************/
#ifndef READ_MENU_HPP
#define READ_MENU_HPP

#include <string>

int readMenu(std::string menu[], int numItems);

#endif
