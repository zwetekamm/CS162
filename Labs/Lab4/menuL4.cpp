/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/15/18
 * Description: Menu function which presents a menu to the user. User provides
 * input which is implemented to other programs.
*******************************************************************************/

#include "menuL4.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::toupper;

// prompt user to begin or quit the program
void menu_begin()
{
	int choice;

	do
	{
		cout << "1. Begin Program" << endl;
		cout << "2. Exit" << endl;
		cin >> choice;
 
		if (std::cin.fail())
		{
			cout << "Invalid choice. Enter 1 or 2. " << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (choice == 2)
		{
			exit(0);
		}

		else if (choice == 1)
		{
			break;
		}
	}
	while (choice != 1 || choice != 2);
}


// validate user input for an integer; will adjust for each project assignment
void menu_getInt(int& input)
{
	int x;
	bool invalid;

	do
	{
		invalid = false;
		cin >> x;

		if(std::cin.fail())
		{
			invalid = true;
			cout << "Input is invalid. Must be an integer." << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		// value between menu options
		else if (x < 1 || x > 4)
		{
			invalid = true;
			cout << "Input is invalid. Must be 1, 2, 3, or 4." << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while(invalid);

	input = x;
}

// validate user input for an integer; specific to choice 3--choose worker--in
// the start() function of class University.
void menu_getWorker(int& input)
{
	int x;
	bool invalid;

	do
	{
		invalid = false;
		cin >> x;

		if(std::cin.fail())
		{
			invalid = true;
			cout << "Input is invalid. Must be an integer." << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		// value between menu options
		else if (x < 1)
		{
			invalid = true;
			cout << "Input is invalid. Must be greater than 1." << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while(invalid);

	input = x;
}

