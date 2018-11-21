/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Header file for the class University.
*******************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "menuL4.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class University
{
	private:
		string name;
		vector<Building*> buildings;
		vector<Person*> people;

	public:
		University();
		~University();
		University(string);
		void setBuilding(Building*);
		void setPerson(Person*);
		void printBuildings();
		void printPeople();
		void chooseDoWork();
		void start();
};

#endif
