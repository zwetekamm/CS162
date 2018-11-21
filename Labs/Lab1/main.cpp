/******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 7/1/18
 * Description: Main file for the functions readMatrix and determinant.  The
 * function asks the user for a matrix size and dynamically allocates the
 * memory space for the matrix.  The function also calculates the determinant
 * and displays the value alongside the matrix.
******************************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <string>

int main() {

	int size = 0;
	int detCalc = 0;

    cout << "Would you like to create a 2x2 or 3x3 matrix?" << endl;
    cout << "Please enter 2 for 2x2, or 3 for 3x3." << endl;
    getInt(size, 2, 3);

	cout << "Okay. We'll create a " << size << "x" << size << " matrix." << endl;

	int** matrix = new int*[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

	readMatrix(matrix, size);

	detCalc = determinant(matrix, size);

	cout << "Here is your matrix:" << endl;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			cout << matrix[r][c] << "\t";
		}
		cout << endl;
	}

	cout << "The determinant is " << detCalc << endl;

	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}

