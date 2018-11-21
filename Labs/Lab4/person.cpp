/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Person
*******************************************************************************/

#include "person.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*********************************************************************
 * Person()
 * Description: Default constructor for Person object.
*********************************************************************/
Person::Person()
{}


/*********************************************************************
 * ~Person()
 * Description: Destructor for Person object.
*********************************************************************/
Person::~Person()
{}


/*********************************************************************
 * Person(string, int)
 * Description: Constructor for Person object with 2 parameters.
*********************************************************************/
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}


/*********************************************************************
 * do_work(int)
 * Description: Virtual function to randomly calculate hours worked.
*********************************************************************/
void Person::do_work()
{
	int hours = (rand() % 6 + 1);
}

/*********************************************************************
 * printPerson()
 * Description: Virtual function to print Student or Instructor
 * information.
*********************************************************************/
void Person::print()
{
	cout << "Person: " << name << endl;
	cout << "Age: " << age << endl;
}

/*********************************************************************
 * getName()
 * Description: Returns the Person object name.
*********************************************************************/
string Person::getName()
{
	return name;
}
