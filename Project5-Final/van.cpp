/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Van.
***********************************************************/

#include "van.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Van()
* Description: Default constructor.
***********************************************************/
Van::Van()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Van()
* Description: Defualt destructor. 
***********************************************************/
Van::~Van()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Van::description()
{
	cout << "Jimmy's walks outside and enters his volkswagon " << endl;
	cout << "van. He puts the keys into the ignition and starts." << endl;
	cout << "He examines the CD player.  Some younger people" << endl;
	cout << "have never heard of the mythic CD device." << endl;
}


/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Van::playerChoice(Player* p)
{
	int choice;

	cout << "----------" << endl;
	cout << "What will Jimmy do?" << endl;
	cout << "1. Move up" << endl;
	cout << "2. Move right" << endl;
	cout << "3. Move down" << endl;
	cout << "4. Move left" << endl;
	cout << "5. Play CD" << endl;

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
				cout << "Jimmy drives away from home." << endl;
				return right;
				break;
			}
			case 3:
			{
				cout << "Jimmy leaves the van and goes into the basement." << endl;
				return down;
				break;
			}
			case 4:
			{
				cout << "Jimmy leaves the van and goes into his home." << endl;
				return left;
				break;
			}
			case 5:
			{
				playCD(p);
				break;
			}
		}
		cout << "Enter another choice: " << endl;
	}
}

/***********************************************************
* playCD(Player)
* Description: Plays the CD item from player inventory; output
* depends if player has a certain CD, if any.
***********************************************************/
void Van::playCD(Player *p)
{
	if (p->searchInventory("sadCD"))
	{
		cout << "Jimmy inserts the CD into the player." << endl;
		cout << "The music is reminiscent of an old flame..." << endl;
	}
	else if(p->searchInventory("happyCD"))
	{
		cout << "Jimmy inserts the CD into the player." << endl;
		cout << "'Dude, these grooves are silky smooth!'" << endl;
		cout << "The upbeat rhythms makes Jimmy drive " << endl;
		cout << "faster (and of course safely). Time " << endl;
		cout << "decreases by 10 mins." << endl;
		p->decreaseTime(1);
	}
	else
	{
		cout << "There's no CD to play music..." << endl;
	}
}

/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Van::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Van::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Van::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Van::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Van::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Van::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Van::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Van::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Van::getLocation()
{
	return VAN;
}