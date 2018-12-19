/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Player.
***********************************************************/
#include "player.hpp"

using std::cout;
using std::endl;
using std::string;

/***********************************************************
* Player() 
* Description: Default constructor.
***********************************************************/
Player::Player()
{
	time = 0;	
}

/***********************************************************
* ~Player() 
* Description: Default destructor.
***********************************************************/
Player::~Player()
{
	while(!inventory.empty())
	{
		delete inventory.back();
		inventory.erase(inventory.end()-1);
	}
}

/***********************************************************
* addItem(Item*)
* Description: Adds item to player inventory using a vector.
* Inventory max is 3 items.
***********************************************************/
void Player::addItem(Item* i)
{
	if (inventory.size() > 3)
	{
		cout << "Jimmy complains he can't hold any more items!" << endl;
	}
	else
	{
		inventory.push_back(i);
	}
}

/***********************************************************
* removeItem(Item*)
* Description: Removes item from player inventory using a vector.
***********************************************************/
void Player::removeItem(string s)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getItem() == s)
		{
			inventory.erase(inventory.begin() + i);
		}
	}
}

/***********************************************************
* printInventory()
* Description: Prints the player's inventory items.
***********************************************************/
void Player::printInventory()
{
	if (inventory.size() == 1)
	{
		cout << inventory[0]->getItem();
	}
	else
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << inventory[i]->getItem();
			if (i + 1 < inventory.size())
			{
				cout << ", ";
			}
			else
			{
				cout << endl;
			}
		}
	}
}


/***********************************************************
* increaseTime()
* Description: Increases the game time.
***********************************************************/
void Player::increaseTime(int n)
{
	time += n;
}


/***********************************************************
* decreaseTime()
* Description: Decreases the game time.
***********************************************************/
void Player::decreaseTime(int n)
{
	time -= n;
}

/***********************************************************
* getTime()
* Description: Returns the game time. 
***********************************************************/
int Player::getTime()
{
	return time;
}

/***********************************************************
* searchInventory(string)
* Description: Searches the player inventory for a specific
* item; returns true if the item is in the inventory.
***********************************************************/
bool Player::searchInventory(string s)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getItem() == s)
		{
			return true;
		}
	}

	return false;
}
