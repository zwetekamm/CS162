/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Player.
***********************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Player
{
	protected:
		vector<Item*> inventory;
		int time;

	public:
		Player();
		~Player();
		void addItem(Item*);
		void removeItem(string);
		void printInventory();
		void increaseTime(int);
		void decreaseTime(int);
		int getTime();
		bool searchInventory(string);
};

#endif