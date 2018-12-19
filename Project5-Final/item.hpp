/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Item.
***********************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item
{
	private:
		string itemName;

	public:
		Item(string);
		virtual ~Item();
		string getItem();
};

#endif