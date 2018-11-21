/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/08/18
 * Description: Main file for a program that reads an input file, counts the
 * letter frequencies in the file, and writes the result to an output file.
*******************************************************************************/

#include "fileIO.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	//declare file input/output strings
	string iFileName;
	string oFileName;

	//create filestreams
	ifstream ifs;
	ofstream ofs;

	//initialize the counter array
	int count[26] = {0};

	cout << "Hello. I'll count letter frequencies in a file." << endl << 
		"What file would you like to read?" << endl;
	
	cin >> iFileName;

	//open the input file
	ifs.open(iFileName.c_str());

	//if no input file cannot be opened
	if(!ifs)
	{
		cout << "Sorry, but that file cannot be located. Run the program again." << endl;
		
		return 1;	
	}

	//while the input file remains open
	while(ifs.good())
	{
		//function for counting frequency sequence
		count_letters(ifs, count);

		//function to promt user for output filename,
		//open file, and write frequency to output file.
		output_letters(ofs, count);		

		//close output file
		ofs.close();
	}

	//close input file
	ifs.close();

	return  0;
}
