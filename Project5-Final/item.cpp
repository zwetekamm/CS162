/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Source file for the class Item.
***********************************************************/
#include "item.hpp"

using std::string;

/***********************************************************
* Item()
* Description: Default constructor. 
***********************************************************/
Item::Item(string itemName)
{
	this->itemName = itemName;
}

// destructor
Item::~Item()
{}

/***********************************************************
* ~Item()
* Description: Default destructor.
***********************************************************/
string Item::getItem()
{
	return itemName;
}
