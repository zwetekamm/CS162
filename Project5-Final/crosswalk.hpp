/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Crosswalk.
***********************************************************/
#ifndef CROSSWALK_HPP
#define CROSSWALK_HPP

#include "space.hpp"

class Crosswalk : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		Location CROSSWALK;

	public:
		Crosswalk();
		~Crosswalk();
		virtual void description();
		Space *playerChoice(Player*);
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