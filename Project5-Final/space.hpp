/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the abstract class Space.
***********************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "player.hpp"
#include "menu.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using std::string;

enum Location {HOME, BASEMENT, VAN, CROSSWALK, PARK, CONCERT};

class Space
{
	protected:
		Space *up;
		Space *right;
		Space *down;
		Space *left;

	public:
		Space();
		virtual ~Space();
		virtual void description() = 0;
		virtual Space *playerChoice(Player*) = 0;
		virtual void setUp(Space*) = 0;
		virtual void setRight(Space*) = 0;
		virtual void setDown(Space*) = 0;
		virtual void setLeft(Space*) = 0;
		virtual Space *getUp() = 0;
		virtual Space *getRight() = 0;
		virtual Space *getDown() = 0;
		virtual Space *getLeft() = 0;
		virtual Location getLocation() = 0;
};

#endif