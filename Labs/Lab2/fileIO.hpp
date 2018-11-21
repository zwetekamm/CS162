/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/08/18
 * Description: Header file for a program that reads a file, counts the letter
 * frequencies in the file, and writes the results to an output file.
*******************************************************************************/

#ifndef FILEIO_HPP
#define FILEIO_HPP
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;

void count_letters(ifstream&, int*);
void output_letters(ofstream&, int*);

#endif
