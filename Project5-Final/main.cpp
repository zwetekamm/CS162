/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Main file for the final project assignment.
***********************************************************/
#include "game.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//sets random seed
	srand(time(NULL));

	int choice;

	cout << "Final Project: Rockstar Jimmy Jams" << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	getInt(choice, 1, 2);

	if (choice == 1)
	{
		Game g;
		g.play();
	}
	
	return 0;
}