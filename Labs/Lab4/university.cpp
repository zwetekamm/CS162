/*******************************************************************************
 * Author: Zachary Wetekamm
 * Date: 07/22/18
 * Description: Source file for the class University.
*******************************************************************************/ 

#include "university.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*********************************************************************
 * University(string)
 * Description: Default constructor for the class University
*********************************************************************/
University::University()
{}


/*********************************************************************
 * ~University()
 * Description: Destructor that sets pointers to NULL.
*********************************************************************/
University::~University()
{}


/*********************************************************************
 * University(string)
 * Description: Constructor for the class University; sets name variable.
*********************************************************************/
University::University(string name)
{
	name = name;
}


/*********************************************************************
 * setBuilding()
 * Description: Sets a pointer to a Building object.
*********************************************************************/
void University::setBuilding(Building *b)
{
	buildings.push_back(b);
}


/*********************************************************************
 * setPerson()
 * Description: Sets a pointer to a Person object
*********************************************************************/
void University::setPerson(Person *p)
{
	people.push_back(p);
}


/*********************************************************************
 * printBuildings()
 * Description: Prints all Building objects; outputs name, address, and size.
 * I found that the iterator function can be used to find addresses
 * within a vector. 
 * https://stackoverflow.com/questions/2395275/how-to-navigate-through-a-vector-using-iterators-c
*********************************************************************/
void University::printBuildings()
{
	//establish the iterator for each building
	vector<Building*>::iterator it;
	int i = 0;

	//navigate each element within the vector and output contents.
	for(it = buildings.begin(); it != buildings.end(); it++, i++)
	{
		buildings[i]->print();
		cout << endl;
	}
}


/*********************************************************************
 * printPeople()
 * Description: Prints all People objects; outputs name, age, GPA or Rating.
 * I found that the iterator function can be used to find addresses
 * within a vector. 
 * https://stackoverflow.com/questions/2395275/how-to-navigate-through-a-vector-using-iterators-c
*********************************************************************/
void University::printPeople()
{
	// establish the iterator for each person
	vector<Person*>::iterator it;
	int i = 0;

	// navigate each element within the vector and output contents.
	for(it = people.begin(); it != people.end(); it++, i++)
	{
		people[i]->print();
		cout << endl;
	}
}

/*********************************************************************
 * chooseDoWork()
 * Description: Menu that prints all people's names.  The user chooses
 * from the menu who will do work. Uses an iterator to navigate the
 * vector.
*********************************************************************/
void University::chooseDoWork()
{
	// establish the iterator for each person.
	vector<Person*>::iterator it;
	int choice,
		i = 0;

	cout << "Choose from available people:" << endl;

	// naviate each person within the vector
	for (it = people.begin(); it != people.end(); it++, i++)
	{
		cout << (i+1) << ": " << people[i]->getName() << endl;
	}

	cout << "Enter your choice: ";

	menu_getWorker(choice);		// validates choice

	while (choice > (i + 1))
	{
		cout << "Invalid. Must be within range." << endl;
		menu_getWorker(choice);
	}

	people[choice-1]->do_work();
}

/*********************************************************************
 * start()
 * Description: Main member function that drives the program. It
 * displays the main menu, sets all the objects for the university,
 * and loops the choice menu for the user.
*********************************************************************/
void University::start()
{
	// Prompt user to begin or exit program; validates input.
	menu_begin();

	// Set all Person and Building objects
	Building *b1 = new Building("Beef Pole Barn", 1080, "3550 Campus Way");
	Building *b2 = new Building("Coastal Oceanography Lab", 2416, "891 SW 30th St");
	Person *s1 = new Student("Zachary", 26, 0.1);
	Person *s2 = new Student("Humble Henry", 50, 3.9); 
   	Person *i1 = new Instructor("Instructor Zhang", 30, 5.0);
    	Person *i2 = new Instructor("Lord Voldemort", 70, 1.8);

	setBuilding(b1);
	setBuilding(b2);
	setPerson(s1);
	setPerson(s2);
	setPerson(i1);
	setPerson(i2);

	int choice;

	// Display main menu, which prompts for 4 input options.
	do
	{
		cout << "1. Print information about all buildings"  << endl;
		cout << "2. Print information of everyone at university" << endl;
		cout << "3. Choose a person to do work" << endl;
		cout << "4. Exit Program" << endl;
		
		menu_getInt(choice);		// validates input

		switch(choice)
		{
			case 1:
			{
				printBuildings();
			 	break;
			}
		    	case 2:
		    	{
				printPeople();
		 		break;
			}
	       		case 3: 
	       		{
				chooseDoWork();
		 		break;
			}
			case 4:
			{
				cout << "Exiting the Program." << endl;
				exit(0);
				break;
			}
		}
	}
	while (choice != 4);
}

