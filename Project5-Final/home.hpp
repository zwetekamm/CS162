/***********************************************************
* Author: Zachary Wetekamm
* Date: 8/15/18
* Description: Header file for the class Home.
***********************************************************/
#ifndef HOME_HPP
#define HOME_HPP

#include "space.hpp"

class Home : public Space
{
	private:
		Space *up;
		Space *right;
		Space *down;
		Space *left;
		Location HOME;

	public:
		Home();
		~Home();
		virtual void description();
		Space *playerChoice(Player*);
		virtual void addCD(Player*);
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