/********************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/29/18
 * Description: Source file for recursion.cpp
********************************************************************/
#include "recursion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

/********************************************************************
 * menu()
 * Description: Main menu function, which prompts the user to choose
 * any of the three recursive funtions of the program or exit. Unless
 * Exit is selected, the menu will prompt after each function
 * exercise.
********************************************************************/
void menu()
{
	cout << "Lab 5: Recursion" << endl;

	int choice;
	while (choice != 4)
	{
		cout << "1. Reverse a string" << endl;
		cout << "2. Sum the elements of an array" << endl;
		cout << "3. Calculate triangular number" << endl;
		cout << "4. Exit Program" << endl;
		getInt(choice, 1, 4);

		switch(choice)
		{
			case 1:
			{
				string str;
				cout << "Enter a string:" << endl;
				getString(str);

				reverseString(str);
				break;
			}

			case 2:
			{
				int size;
				cout << "How many elements for the array?" << endl;
				getInt(size, 1, 100);

				int array[size];
				int element;
				cout << "Enter the value for each element:" << endl;

				for (int i = 0; i < size; i++)
				{
					cout << "Value for element " << i + 1 << endl;
					getInt(element, 1, 100);
					array[i] = element;
				}

				cout << "Sum: " << sumArray(array, size) << endl;
				break;
			}

			case 3:
			{
				int n;
				cout << "Enter an integer: " << endl;
				getInt(n, 1, 100);

				cout << "Triangular of " << n << ": ";
				for (int i = 0; i < n; i++)
				{
					cout << i + 1;
					if (i + 1 < n)
						{cout << " + ";}
					else
						{cout << " = ";}
				}
				
				cout << triangularNum(n) << endl;
				break;
			}

			case 4:
			{
				cout << "Exiting the program..." << endl;
				break;
			}
		}
	}
}


/********************************************************************
 * reverseString(string)
 * Description: Recursive function that outputs a string in reverse
 * order. Takes a string as an argument. The length of the string
 * is used stored an 'n' and is used to output the string from end
 * to beginning.
********************************************************************/
void reverseString(string s)
{
	// get the length of the passed argument
	int n = s.length();

	// establish the base case
	if (n == 0)
	{
		cout << s << '\n';
	}

	// call the last letter in the string s
	// using substr() (textbook ch. 12)
	else
	{
		cout << s[n - 1];
		reverseString(s.substr(0, n - 1));
	}
}


/********************************************************************
 * sumArray(int*, int)
 * Description: Recursive function that calculates the sum of an
 * array of integers. Takes--as arguments--a pointer to an integer
 * array and an integer n, which is the array size. The function sums
 * from the end of the array to the beginning (ex. n - 1), eventually 
 * reaching the base case.
********************************************************************/
int sumArray(int* arr, int n)
{
	// establish the base case
	if (n == 0)
	{
		return 0;
	}

	else
	{
		return arr[n-1] + sumArray(arr, n-1);
	}
}


/********************************************************************
 * triangularNum(int)
 * Description: Recursive function that calculates the triangular
 * number of an integer. E.g. triangular 4 is 1 + 2 + 3 + 4 = 10.
********************************************************************/
int triangularNum(int n)
{
	// establish the base case
	if (n == 1)
	{
		return n;
	}

	// return n - 1
	else
	{
		return n + triangularNum(n-1);
	}
}
