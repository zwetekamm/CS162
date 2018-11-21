/******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 7/1/18
 * Description: Source file for function determinant, which calculates the
 * determinant value for either a 2x2 or 3x3 matrix.
******************************************************************************/
#include "determinant.hpp"

int determinant(int** matrix, int size) {
	int detValue = 0;

	if(size == 2) {
		int a = matrix[0][0];
		int b = matrix[0][1];
		int c = matrix[1][0];
		int d = matrix[1][1];

		detValue = (a * d) - (b * c);

		return detValue;

	} else if(size == 3) {
		int a = matrix[0][0];
		int b = matrix[0][1];
		int c = matrix[0][2];
		int d = matrix[1][0];
		int e = matrix[1][1];
		int f = matrix[1][2];
		int g = matrix[2][0];
		int h = matrix[2][1];
		int i = matrix[2][2];

		detValue = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);

		return detValue;
	}
}
