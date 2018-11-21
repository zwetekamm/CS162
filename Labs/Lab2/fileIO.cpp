/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/08/18
 * Description: This program reads an input file, counts the letter
 * frequencies for each paragraph in the file, and writes the results to an 
 * output file.
*******************************************************************************/
#include "fileIO.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::tolower;

/******************************************************************************
 * count_letters(ifstream&, int*)
 * Description: Function first gets a line from input file, converts all 
 * letters to lowercase, and uses ascii values to increment the array count.
*******************************************************************************/
 void count_letters(ifstream& ifs, int* count)
{	
	//string for an entire line
	string line;
	char ch;
	int i = 0;

	//reads entire line
	getline(ifs, line);

	//initialize the counter to 0 for new line
	for(i=0; i < 26; i++)
	{
		count[i] = 0;
	}

	//loop increment based on line length
	for(i=0; i < line.length(); i++)
	{
		//convert to lowercase
		ch = tolower(line[i]);

		//increment count if between ascii values
		if((int)ch >= 97 && (int)ch <= 122)
		{	
			count[(int)ch-97] += 1;
		}
	}
}


/******************************************************************************
 * output_letters(ofstream&, int*)
 * Description: Function asks user for output file name, opens the 
 * file, then adds the count[] frequency to the file. Output format
 * is one line per alphabetical character.
******************************************************************************/
void output_letters(ofstream& ofs, int* count)
{
	//declare output filename
	string oFileName;
	int i;
	int numLine = 1;

	//prompt user to enter output filename
	cout << "Enter output file name for each line: "; 
	cin >> oFileName;

	//open outfile to stream
	ofs.open(oFileName.c_str());
	
	//increment and write to output file.  Character is written
	//to the output file using ascii value and the frequency
	//values from the count array are shown.
	for(i=0; i < 26; i++)
	{
		ofs << (char)(i + 97) << ": " << count[i] << endl;
	}
}
