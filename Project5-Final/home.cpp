/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Home.
***********************************************************/

#include "home.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Home()
* Description: Default constructor.
***********************************************************/
Home::Home()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Home()
* Description: Defualt destructor. 
***********************************************************/
Home::~Home()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Home::description()
{
	cout << "Jimmy's room is messy, but he needs his " << endl;
	cout << "guitar for the concert. It's not in the room, " << endl;
	cout << "but must be in the house." << endl;
	cout << "Jimmy may also want to bring a CD to jam " << endl;
	cout << "while driving to the concert." << endl;
}


/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Home::playerChoice(Player* p)
{
	int choice;

	cout << "----------" << endl;
	cout << "What will Jimmy do?" << endl;
	cout << "1. Move up" << endl;
	cout << "2. Move right" << endl;
	cout << "3. Move down" << endl;
	cout << "4. Move left" << endl;
	cout << "5. Get a CD for the car" << endl;

	while (true)
	{
		getInt(choice, 1, 5);
		
		switch (choice)
		{
			case 1:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}
			case 2:
			{
				cout << "Jimmy goes outside to the van." << endl;
				return right;
				break;
			}
			case 3:
			{
				cout << "Jimmy goes to the basement." << endl;
				return down;
				break;
			}
			case 4:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}
			case 5:
			{
				// if player has already picked up the CD
				if (p->searchInventory("sadCD") || p->searchInventory("happyCD"))
				{
					cout << "Jimmy already has a CD." << endl;
				}
				else
				{
					addCD(p);
				}
				break;
			}
		}
		cout << "Enter another choice: " << endl;
	}
}

/***********************************************************
* addCD(Player)
* Description: Adds a random CD item to player inventory.
***********************************************************/
void Home::addCD(Player *p)
{
	int roll = rand() % 2;

	cout << "Jimmy takes a random CD." << endl;
	
	if (roll == 0)
	{
		p->addItem(new Item("sadCD"));
	}
	else
	{
		p->addItem(new Item("happyCD"));
	}
}

/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Home::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Home::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Home::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Home::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Home::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Home::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Home::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Home::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Home::getLocation()
{
	return HOME;
}