/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Crosswalk.
***********************************************************/

#include "crosswalk.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Crosswalk()
* Description: Default constructor.
***********************************************************/
Crosswalk::Crosswalk()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Crosswalk()
* Description: Defualt destructor. 
***********************************************************/
Crosswalk::~Crosswalk()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Crosswalk::description()
{
	cout << "Jimmy approaches the crosswalk. He slows down as " << endl;
	cout << "a woman with long black hair crosses. She looks so " << endl;
	cout << "familiar to him...it is his ex-lover! She broke his heart." << endl;
}


/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Crosswalk::playerChoice(Player* p)
{
	int choice;

	if (!p->searchInventory("sadCD"))
	{
		cout << "----------" << endl;
		cout << "What will Jimmy do?" << endl;
		cout << "1. Move up" << endl;
		cout << "2. Move right" << endl;
		cout << "3. Move down" << endl;
		cout << "4. Move left" << endl;
	}

	while (true)
	{
		// Jimmy must go to the park if has sadCD
		if (p->searchInventory("sadCD"))
		{
			choice = 3;
		}
		else
		{
			getInt(choice, 1, 4);
		}

		switch (choice)
		{
			case 1:
			{
				cout << "Jimmy has a short memory...he continues " << endl;
				cout << "on towards the concert." << endl;
				return up;
				break;
			}
			case 2:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}
			case 3:
			{
				if (!p->searchInventory("sadCD"))
				{
					cout << "Jimmy has a short memory...he drives to " << endl;
					cout << "the park." << endl;
					return down;
					break;
				}
				else
				{
					cout << "'My heart!' cries Jimmy Jams. He is a true " << endl;
					cout << "romantic, and deep melancholy washes over " << endl;
					cout << "Without hesitation, he turns around and " << endl;
					cout << "drives to the park to lift his sorrows..." << endl;
					return down;
					break;
				}
			}
			case 4:
			{
				cout << "Jimmy drives back to the house." << endl;
				return left;
				break;
			}
		}
		cout << "Enter another choice: " << endl;
	}
}

/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Crosswalk::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Crosswalk::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Crosswalk::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Crosswalk::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Crosswalk::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Crosswalk::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Crosswalk::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Crosswalk::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Crosswalk::getLocation()
{
	return CROSSWALK;
}