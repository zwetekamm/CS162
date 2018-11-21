/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class Building.
*******************************************************************************/ 

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
#include <iostream>

using std::string;

class Building
{
	private:
		string name;
		int size;
		string address;

	public:
		Building();
		~Building();
		Building(string, int, string);
		void print();
};

#endif
