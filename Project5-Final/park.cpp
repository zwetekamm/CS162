/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Park.
***********************************************************/

#include "park.hpp"

using std::cout;
using std::endl;

/***********************************************************
* Park()
* Description: Default constructor.
***********************************************************/
Park::Park()
{
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

/***********************************************************
* ~Park()
* Description: Defualt destructor. 
***********************************************************/
Park::~Park()
{}


/***********************************************************
* description()
* Description: Displays information about this Space.
***********************************************************/
void Park::description()
{
	cout << "The park is serene.  Jimmy sits by a small pond." << endl;
}


/***********************************************************
* playerChoice(Player*)
* Description: Move function for the player, which returns
* a pointer to a different Space object. Interative choices
* are included with each Space.
***********************************************************/
Space* Park::playerChoice(Player* p)
{
	int choice;

	if (p->searchInventory("sadCD"))
	{
		cout << "Jimmy meditates in the park--his long, " << endl;
		cout << "greasy hair flutters in the breeze. No one " << endl;
		cout << "minds the aspiring buddha. His spirits are " << endl;
		cout << "lifted but it took 30 mins. You must hurry!" << endl;
		p->removeItem("sadCD");
		p->increaseTime(3);
	}
	else
	{
		cout << "Why go to the park? The concert is the other way!" << endl;
		cout << "Jimmy get distracted and feeds ducks by the pond." << endl;
		cout << "Time increases by 20 mins." << endl;
		p->increaseTime(2);

		if (p->searchInventory("Guitar"))
		{
			addDuck(p);
		}
	}

	cout << "----------" << endl;
	cout << "What will Jimmy do?" << endl;
	cout << "1. Move up" << endl;
	cout << "2. Move right" << endl;
	cout << "3. Move down" << endl;
	cout << "4. Move left" << endl;

	while (true)
	{
		getInt(choice, 1, 4);

		switch (choice)
		{
			case 1:
			{
				cout << "Jimmy drives to the crosswalk." << endl;
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
				cout << "Nothing is there. Check the map." << endl;
				break;
			}
			case 4:
			{
				cout << "Nothing is there. Check the map." << endl;
				break;
			}
		}
		cout << "Enter another choice: " << endl;
	}
}

/***********************************************************
* addDuck(Player*))
* Description: Adds a Duck item to the player inventory.
***********************************************************/
void Park::addDuck(Player* p)
{
	cout << "Jimmy plays guitar for the ducks, and they show " << endl;
	cout << "likeness to him. Jimmy takes one duck with him " << endl;
	cout << "for obvious reasons." << endl;
	p->addItem(new Item("Duck"));
}

/***********************************************************
* setUp(Space*)
* Description: Sets the up pointer of this space.
***********************************************************/
void Park::setUp(Space *s)
{
	up = s;
}

/***********************************************************
* setRight(Space*)
* Description: Sets the right pointer of this space.
***********************************************************/
void Park::setRight(Space *s)
{
	right = s;
}

/***********************************************************
* setDown(Space*)
* Description: Sets the down pointer of this space.
***********************************************************/
void Park::setDown(Space *s)
{
	down = s;
}

/***********************************************************
* setLeft(Space*)
* Description: Sets the left pointer of this space.
***********************************************************/
void Park::setLeft(Space *s)
{
	left = s;
}

/***********************************************************
* getUp()
* Description: Returns the up pointer of this space.
***********************************************************/
Space* Park::getUp()
{
	return up;
}

/***********************************************************
* getRight()
* Description: Returns the right pointer of this space.
***********************************************************/
Space* Park::getRight()
{
	return right;
}

/***********************************************************
* getDown()
* Description: Returns the down pointer of this space.
***********************************************************/
Space* Park::getDown()
{
	return down;
}

/***********************************************************
* getLeft()
* Description: Returns the left pointer of this space.
***********************************************************/
Space* Park::getLeft()
{
	return left;
}

/***********************************************************
* getRoom()
* Description: Returns the Location data type of this space.
***********************************************************/
Location Park::getLocation()
{
	return PARK;
}