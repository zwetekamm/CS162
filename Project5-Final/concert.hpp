/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Concert.
***********************************************************/
#ifndef CONCERT_HPP
#define CONCERT_HPP

#include "space.hpp"

class Concert : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		bool result;
		Location CONCERT;

	public:
		Concert();
		virtual ~Concert();
		virtual void description();
		Space *playerChoice(Player*);
		virtual void setUp(Space*);
		virtual void setRight(Space*);
		virtual void setDown(Space*);
		virtual void setLeft(Space*);
		virtual bool getResult();
		virtual Space *getUp();
		virtual Space *getRight();
		virtual Space *getDown();
		virtual Space *getLeft();
		virtual Location getLocation();
};

#endif