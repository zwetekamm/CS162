/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Park.
***********************************************************/
#ifndef PARK_HPP
#define PARK_HPP

#include "space.hpp"

class Park : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		Location PARK;

	public:
		Park();
		~Park();
		virtual void description();
		Space *playerChoice(Player*);
		virtual void addDuck(Player*);
		virtual void setUp(Space*);
		virtual void setRight(Space*);
		virtual void setDown(Space*);
		virtual void setLeft(Space*);
		virtual Space *getUp();
		virtual Space *getRight();
		virtual Space *getDown();
		virtual Space *getLeft();
		virtual Location getLocation();
};

#endif