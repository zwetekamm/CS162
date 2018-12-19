/*************************************************************************
 * Date:         July 29, 2018
 * Description:  This is the implementation file for the function readMenu().
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
#include <iostream>
#include <string>
#include "getValidData.hpp"

using std::cout;
using std::endl;
using std::string;

void printMenu(string menu[], int numItems);

int readMenu(string menu[], int numItems)
{
    int userChoice;

    //Prints numbers by each menu option for the user
    printMenu(menu, numItems);

    //Gets and validates menu choice from the user
    cout << "Please enter your choice and press enter: ";
    getValidData(userChoice, 1, numItems);

    return userChoice;
}

void printMenu(string menu[], int numItems)
{
    for (int x = 0; x < numItems; x++)
    {
        cout << x + 1 << ". " << menu[x] << endl;
    }
}
