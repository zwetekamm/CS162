/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Basement.
***********************************************************/

#include "basement.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Basement()
* Description: Default constructor.
***********************************************************/
Basement::Basement()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Basement()
* Description: Defualt destructor. 
***********************************************************/
Basement::~Basement()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Basement::description()
{
	cout << "The basement is messy, but this is where Jimmy " << endl;
	cout << "practices. His guitar rests on the couch; on  " << endl;
	cout << "the table is leftover pizza. Jimmy is hungry, " << endl;
	cout << "but he forgets which day he ordered that pizza..." << endl;
}


/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Basement::playerChoice(Player* p)
{
	int choice;

	cout << "----------" << endl;
	cout << "What will Jimmy do?" << endl;
	cout << "1. Move up" << endl;
	cout << "2. Move right" << endl;
	cout << "3. Move down" << endl;
	cout << "4. Move left" << endl;
	cout << "5. Get the guitar" << endl;
	cout << "6. Eat a slice of 'zza" << endl;

	while (true)
	{
		getInt(choice, 1, 6);
		
		switch (choice)
		{
			case 1:
			{
				cout << "Jimmy goes up to the house." << endl;
				return up;
				break;
			}
			case 2:
			{
				cout << "Jimmy goes up through the garage into the van." << endl;
				return right;
				break;
			}
			case 3:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}

			case 4:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}

			case 5:
			{	
				// if player has already picked up the guitar
				if (p->searchInventory("Guitar"))
				{
					cout << "Jimmy already has the guitar" << endl;
				}
				else
				{
					addGuitar(p);
				}
				break;
			}
			case 6:
			{
				// if player already ate the pizza
				if (p->searchInventory("Pizza"))
				{
					cout << "Jimmy already at the 'zza." << endl;
				}
				else
				{
					eatPizza(p);
				}
				break;
			}
			cout << "Enter another choice:" << endl;
		}
	}
}

/***********************************************************
* addGuitar(Player*)
* Description: Adds the Guitar item to player inventory.
***********************************************************/
void Basement::addGuitar(Player *p)
{
	cout << "Jimmy picks up the guitar and shreds " << endl;
	cout << "a few chords.  But he is lost in the " << endl;
	cout << "moment, and takes 10 mins. He slings the " << endl;
	cout << "guitar on his back and nods." << endl;
	p->addItem(new Item("Guitar"));
	p->increaseTime(1);
}

/***********************************************************
* eatPizza(Player*)
* Description: Decrease time by 1 (10 mins).
***********************************************************/
void Basement::eatPizza(Player *p)
{
	cout << "Jimmy chows on the 'zza." << endl;
	cout << "He feels a surge of energy, and " << endl;
	cout << "bends space-time. Time decreases 10 mins." << endl;
	p->decreaseTime(1);
}

/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Basement::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Basement::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Basement::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Basement::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Basement::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Basement::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Basement::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Basement::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Basement::getLocation()
{
	return BASEMENT;
}