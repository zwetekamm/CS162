/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Student.
*******************************************************************************/ 

#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;

/*********************************************************************
 * Student()
 * Description: Default constructor.
*********************************************************************/
Student::Student()
{}


/*********************************************************************
 * Student(string, int, float)
 * Description: Constructor which creates a Student object using the
 * name and age variables from a Person object.
*********************************************************************/
Student::Student(string name, int age, float gpa)
{
	this->name = name;
	this->age = age;
	
	//set gpa within range 0 - 4.0
	if (gpa > 4.0)
	{
		this->gpa = 4.0;
	}
	else if (gpa < 0.0)
	{
		this->gpa = 0.0;
	}
	else
	{
		this->gpa = gpa;
	}
}

/*********************************************************************
 * do_work()
 * Description: Virtual function that generates a random number of 
 * homework hours for a Student object.
*********************************************************************/
void Student::do_work()
{
	int hours = (rand() % 6 + 1);		// randomly generated number (within reason)

	cout << name << " did " << hours << " hours of homework." << endl;
}

/*********************************************************************
 * printPerson()
 * Description: Virtual function that will distinguish between student
 * and instructor. Student's display GPA, while instructors do not.
*********************************************************************/
void Student::print()
{
	cout << "Student: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "GPA: " << gpa << endl;
}


/*********************************************************************
 * getName()
 * Description: Returns the name of a Student object.
*********************************************************************/
string Student::getName()
{
	return name;
}
