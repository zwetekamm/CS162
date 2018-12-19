/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Van.
***********************************************************/
#ifndef VAN_HPP
#define VAN_HPP

#include "space.hpp"

class Van : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		Location VAN;

	public:
		Van();
		~Van();
		virtual void description();
		Space *playerChoice(Player*);
		virtual void playCD(Player*);
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