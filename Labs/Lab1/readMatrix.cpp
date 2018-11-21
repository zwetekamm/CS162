/******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 7/1/18
 * Description: Source file for the function readMatrix, which prompts the
 * user to input values for a matrix.  The function uses letters to display
 * an example matrix to the user, which helps visualize a desired matrix.
******************************************************************************/
#include "readMatrix.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void readMatrix(int** matrix, int size) {
	if (size == 2) {
		cout << "Here's an example 2x2 matrix:" << endl
                << "a  b" << endl
                << "c  d" << endl;
        cout << "Type a value and press enter." << endl;
        cout << "(Values are stored in alphabetical order shown above" << endl;
	} else if (size == 3) {
		cout << "Here's an example 3x3 matrix:" << endl
		     << "a  b  c" << endl
		     << "d  e  f" << endl
		     << "g  h  i" << endl;
        cout << "Type a value and press enter." << endl;
        cout << "(Values are stored in alphabetical order shown above)" << endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
            cout << "Element " << i + 1 << ": ";
			cin >> matrix[i][j];
            cout << endl;
		}
	}
}
