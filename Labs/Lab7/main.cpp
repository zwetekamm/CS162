/**********************************************************
* Author: Zachary Wetekamm
* Date : 8/12/18
* Description: Main file for Lab 7, which implements use
* of stack and queue containers.
**********************************************************/
#include "queue.hpp"
#include "stack.hpp"
#include "menu.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	int choice;

	while (choice != 3)
	{
		cout << "Lab 7: STL Containers" << endl;
		cout << "1. Queue buffer" << endl;
		cout << "2. Stack palindrome" << endl;
		cout << "3. Exit program." << endl;
		getInt(choice, 1, 3);

		switch (choice)
		{
			case 1:	// Queue buffer
			{
				Queue userQueue;
				int r, nAdd, nRemove;

				cout << "How many rounds will be simulated?" << endl;
				getInt(r, 1, 100);

				cout << "Enter percentage (as integer 1-100) to add a " << endl;
				cout << "randomly generated number at the end of the buffer." << endl;
				getInt(nAdd, 1, 100);

				cout << "Enter percentage (as integer 1-100) to remove a" << endl;
				cout << "randomly generated number at the front of the buffer." << endl;
				getInt(nRemove, 1, 100);

				userQueue.simulation(r, nAdd, nRemove);
				break;
			}

			case 2: // Stack palindrome
			{
				Stack userStack;
				string s;

				cout << "Enter a string to show as a palindrome: " << endl;
				getString(s);

				cout << userStack.palindrome(s) << endl;
				break;
			}
		}
	}

	return 0;
}