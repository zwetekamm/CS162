/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class Instructor.
*******************************************************************************/ 

#include "instructor.hpp"
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

/*******************************************************************************
 * Instructor()
 * Description: Default constructor for the Instructor object.
*******************************************************************************/
Instructor::Instructor()
{}


/*******************************************************************************
 * ~Instructor()
 * Description: Default destructor for the Instructor object.
********************************************************************************/
Instructor::~Instructor()
{}


/*******************************************************************************
 * Instructor(string, int, float)
 * Constructor for an Instructor object that uses the
 * name and age elements of a Person object.
********************************************************************************/
Instructor::Instructor(string name, int age, float rating)
{
	this->name = name;
	this->age = age;

	// set rating within range
	if (rating > 5.0)
	{
		this->rating = 5.0;
	}
	else if (rating < 0.0)
	{
		this->rating = 0.0;
	}
	else
	{
		this->rating = rating;
	}
}

/*******************************************************************************
 * do_work()
 * Randomly generates an integer hours for grading papers.
*******************************************************************************/
void Instructor::do_work()
{
	int hours = (rand() % 6 + 1);		// randomly generated number (within reason).

	cout << name << " graded papers for " << hours << " hours." << endl;
}


/*******************************************************************************
 * print()
 * Description: Prints the Instructor object.
*******************************************************************************/
void Instructor::print()
{
	cout << "Instructor: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Rating: " << rating << endl;
}


/*******************************************************************************
 * getName()
 * Description: Returns the name of an Instructor object.
*******************************************************************************/
string Instructor::getName()
{
	return name;
}
