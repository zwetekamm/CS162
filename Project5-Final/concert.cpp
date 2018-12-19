/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Concert.
***********************************************************/

#include "concert.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Concert()
* Description: Default constructor.
***********************************************************/
Concert::Concert()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Concert()
* Description: Default destructor. 
***********************************************************/
Concert::~Concert()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Concert::description()
{
	cout << "====================" << endl;
	cout << "Jimmy parks his van and walks as fast as " << endl;
	cout << "a stylish rockstar can with tight leather " << endl;
	cout << "pants. He is ushered by the stage director " << endl;
	cout << "as his set is about to begin." << endl;
}

/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Concert::playerChoice(Player* p)
{
	int choice;
	cout << "----------" << endl;
	cout << "Jimmy is ready to rock!" << endl;
	cout << "What will Jimmy do?" << endl;
	cout << "1. Rock on" << endl;
	cout << "2. Not rock on" << endl;
	getInt(choice, 1, 2);

	int i = 0;
	while (choice == 2)
	{
		if (i > 0)
		{
			cout << "Seriously. The world needs Jimmy Jams..." << endl; 
		}
		else
		{
			cout << "Really? We made it this far! Think again." << endl;
		}
		cout << "1. Rock on" << endl;
		cout << "2. Not rock on" << endl;
		getInt(choice, 1, 2);
		i++;
	}
	return up;
}


/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Concert::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Concert::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Concert::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Concert::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getResult()
* Description: Returns the boolean result.
***********************************************************/
bool Concert::getResult()
{
	return result;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Concert::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Concert::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Concert::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Concert::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Concert::getLocation()
{
	return CONCERT;
}